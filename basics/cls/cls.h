class Abc{
    public:
        int _h;
        int _w;
        Abc() :_h{}, _w{}
        {}
        Abc(int intial_h, int intial_w)
            :_h{intial_h}, _w{intial_w}
        {}
        Abc(int intial_h):_h{intial_h}, _w{} {}
        int getArea()
        {return _h*_w;}
};
