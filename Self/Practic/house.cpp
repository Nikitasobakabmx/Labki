#include <doski>
#include <kirpichi>

struct home{
    int kirpichi;
    int doski;
    float divan;
    char *telek;
};

struct home build(struct home dom){
    dom.kirpichi = 100;
    dom.doski = 200;
    dom.divan = 150;
    dom.telek = "smotry";
    return dom;
}

int main(){
    struct home dom;
    dom = build(dom);
    return 0;
}