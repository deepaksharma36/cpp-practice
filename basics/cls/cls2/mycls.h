#include<vector>

class mycls{

    public:
        explicit mycls(): _h{}, _w{}, _l{}, _group(0) {}
        explicit mycls(int h): _h{h}, _w{}, _l{}, _group(0) {}
        explicit mycls(int h, int w): _h{h}, _w{w}, _l{}, _group(0) {}
        explicit mycls(int h, int w, int l): _h{h}, _w{w}, _l{l}, _group(0) {}
        explicit mycls(int h, int w, int l, int size): _h{h}, _w{w}, _l{l}, _group(size) {}


        int getVol(){
            for(int i=0; i<_group.size(); i++)
                std::cout<<_group[i]<<std::endl;
            return _h*_w*_l;}

    private:
        int _h, _w, _l;
        std::vector<int> _group;
};
