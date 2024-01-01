#pragma once

class Remote;

class Tv
{
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
public:
    friend class Remote;  
    enum { Off, On };
    enum { MinVal, MaxVal = 20 };
    enum { Antenna, Cable };
    enum { TV, DVD };

    Tv(int s = Off, int mc = 125) : state(s), volume(5),
        maxchannel(mc), channel(2), mode(Cable), input(TV)
    {}

    void OnOff() { state = (state == On) ? Off : On; }
    bool IsOn() const { return state == On; }
    bool VolUp();
    bool VolDown();
    void ChanUp();
    void ChanDown();
    void SetMode() { mode = (mode == Antenna) ? Cable : Antenna; }
    void SetInput() { input = (input == TV) ? DVD : TV; }
    void Settings() const;  
    void ChangeControlMode(Remote& r) const;

};

class Remote
{
private:
    int mode;  
    int controlMode;
public:
    friend class Tv;
    enum { Normal, Interactive };
    Remote(int m = Tv::TV, int c = Normal) : mode(m), controlMode(c) {}
    bool VolUp(Tv& t) { return t.VolUp(); }
    bool VolDown(Tv& t) { return t.VolDown(); }
    void OnOff(Tv& t) { t.OnOff(); }
    void ChanUp(Tv& t) { t.ChanUp(); }
    void ChanDown(Tv& t) { t.ChanDown(); }
    void SetChan(Tv& t, int c) { t.channel = c; }
    void SetMode(Tv& t) { t.SetMode(); }
    void SetInput(Tv& t) { t.SetInput(); }
    void ShowContrloMode() const;
};

