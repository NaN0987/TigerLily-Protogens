#pragma once

#include "../Templates/ProtogenProjectTemplate.h"
#include "../../Assets/Models/OBJ/DeltaDisplayBackground.h"
#include "../../Assets/Models/FBX/NukudeFlat.h"

#include "../../Camera/CameraManager/Implementations/HUB75DeltaCameras.h"
#include "../../Controller/HUB75Controller.h"

// Swap the MainFace class for the desired protogen face
using MainFace = NukudeFace;

class ProtogenHUB75Project : public ProtogenProject {
private:
    HUB75DeltaCameraManager cameras;
    HUB75Controller controller = HUB75Controller(&cameras, 50, 50);
    MainFace pM;
    DeltaDisplayBackground deltaDisplayBackground;
    
	const __FlashStringHelper* faceArray[10] = {F("DEFAULT"), F("ANGRY"), F("DOUBT"), F("FROWN"), F("LOOKUP"), F("SAD"), F("AUDIO1"), F("AUDIO2"), F("AUDIO3")};

    void LinkControlParameters() override {//Called from parent
        AddParameter(MainFace::Anger, pM.GetMorphWeightReference(MainFace::Anger), 15);
        AddParameter(MainFace::Sadness, pM.GetMorphWeightReference(MainFace::Sadness), 15, IEasyEaseAnimator::InterpolationMethod::Cosine);
        AddParameter(MainFace::Surprised, pM.GetMorphWeightReference(MainFace::Surprised), 15);
        AddParameter(MainFace::Doubt, pM.GetMorphWeightReference(MainFace::Doubt), 15);
        AddParameter(MainFace::Frown, pM.GetMorphWeightReference(MainFace::Frown), 15);
        AddParameter(MainFace::LookUp, pM.GetMorphWeightReference(MainFace::LookUp), 15);
        AddParameter(MainFace::LookDown, pM.GetMorphWeightReference(MainFace::LookDown), 15);

        AddParameter(MainFace::HideBlush, pM.GetMorphWeightReference(MainFace::HideBlush), 15, IEasyEaseAnimator::InterpolationMethod::Cosine, true);

        AddViseme(Viseme::MouthShape::EE, pM.GetMorphWeightReference(MainFace::vrc_v_ee));
        AddViseme(Viseme::MouthShape::AH, pM.GetMorphWeightReference(MainFace::vrc_v_aa));
        AddViseme(Viseme::MouthShape::UH, pM.GetMorphWeightReference(MainFace::vrc_v_dd));
        AddViseme(Viseme::MouthShape::AR, pM.GetMorphWeightReference(MainFace::vrc_v_rr));
        AddViseme(Viseme::MouthShape::ER, pM.GetMorphWeightReference(MainFace::vrc_v_ch));
        AddViseme(Viseme::MouthShape::OO, pM.GetMorphWeightReference(MainFace::vrc_v_oh));
        AddViseme(Viseme::MouthShape::SS, pM.GetMorphWeightReference(MainFace::vrc_v_ss));

        AddBlinkParameter(pM.GetMorphWeightReference(MainFace::Blink));
    }

    void Default(){}

    void Angry(){
        AddParameterFrame(MainFace::Anger, 1.0f);
        SetMaterialOpacity(Color::CRED);
    } 

    void Sad(){
        AddParameterFrame(MainFace::Sadness, 1.0f);
        AddParameterFrame(MainFace::Frown, 1.0f);
        SetMaterialOpacity(Color::CBLUE);
    }

    void Surprised(){
        AddParameterFrame(MainFace::Surprised, 1.0f);
        AddParameterFrame(MainFace::HideBlush, 0.0f);
        SetMaterialOpacity(Color::CRAINBOW);
    }
    
    void Doubt(){
        AddParameterFrame(MainFace::Doubt, 1.0f);
    }
    
    void Frown(){
        AddParameterFrame(MainFace::Frown, 1.0f);
    }

    void LookUp(){
        AddParameterFrame(MainFace::LookUp, 1.0f);
    }

    void LookDown(){
        AddParameterFrame(MainFace::LookDown, 1.0f);
    }

    void SpectrumAnalyzerCallback() override {
        SetMaterialOpacity(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    void AudioReactiveGradientCallback() override {
        SetMaterialOpacity(Color::CHORIZONTALRAINBOW, 0.8f);
    }

    void OscilloscopeCallback() override {
        SetMaterialOpacity(Color::CHORIZONTALRAINBOW, 0.8f);
    }

public:
    ProtogenHUB75Project() : ProtogenProject(&cameras, &controller, 2, Vector2D(), Vector2D(192.0f, 94.0f), 22, 23, 9){
        scene.AddObject(pM.GetObject());
        scene.AddObject(deltaDisplayBackground.GetObject());

        pM.GetObject()->SetMaterial(GetFaceMaterial());
        deltaDisplayBackground.GetObject()->SetMaterial(GetFaceMaterial());

        hud.SetFaceArray(faceArray);

        LinkControlParameters();
        
        SetWiggleSpeed(5.0f);
        SetMenuWiggleSpeed(0.0f, 0.0f, 0.0f);
        SetMenuOffset(Vector2D(17.5f, -3.0f));
        SetMenuSize(Vector2D(192, 56));
    }

    void Update(float ratio) override {
        pM.Reset();

        uint8_t mode = Menu::GetFaceState();//change by button press

        controller.SetBrightness(Menu::GetBrightness());
        controller.SetAccentBrightness(Menu::GetAccentBrightness());

#ifdef MORSEBUTTON
        SelectFaceFromMorse(mode);
#else
        SelectFace(mode);
#endif

        UpdateFace(ratio);

        pM.Update();

        AlignObjectFace(pM.GetObject(), -7.5f);

        pM.GetObject()->GetTransform()->SetPosition(GetWiggleOffset());
        pM.GetObject()->UpdateTransform();
    }

    void SelectFace(uint8_t code) {
        if (IsBooped() && code != 6) {
            Surprised();
            return;
        }

        switch(code) {
            case 0: Default();  break;
            case 1: Angry();    break;
            case 2: Doubt();    break;
            case 3: Frown();    break;
            case 4: LookUp();   break;
            case 5: Sad();      break;
            case 6: AudioReactiveGradientFace();    break;
            case 7: OscilloscopeFace();             break;
            default: SpectrumAnalyzerFace();        break;
        }
    }

    void SelectFaceFromMorse(uint8_t code) {
        if (IsBooped() && code != 24) {
            Surprised();
            return;
        }

        switch(code) {
            case 1: Angry();        break; // [A]ngry
            case 2: Surprised();    break; // [B]lush
            case 4: Doubt();        break; // [D]oubt
            case 6: Frown();        break; // [F]rown
            case 19: Sad();         break; // [S]ad
            case 21: LookUp();      break; // Look [U]p
            case 22: LookDown();    break; // Look [V] Down
            case 24: AudioReactiveGradientFace();   break; // [X] X.X
            case 25: OscilloscopeFace();            break; // [Y] Oscilloscope
            case 26: SpectrumAnalyzerFace();        break; // [Z] Spectrum
            default: Default();     break; // [H] Happy
        }
    }
};
