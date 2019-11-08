//gcc -c '-I'"$PWD/src" GeometryLibrary.c

#include "geometria.h"
#include <math.h>

//  01. Calcula o produto interno <u,v>
double produto_interno(vetor u, vetor v){
    return u.x * v.x + u.y * v.y;
}

//  02. Calcula o vetor u - v
vetor subtrai(vetor u, vetor v){
    return (vetor) {u.x - v.x, u.y - v.y};
}        

/*  03. Calcula o vetor resultante da rotação do vetor v
    de um ângulo de 90 graus no sentido anti-horário. */
vetor roda90(vetor v){
    return (vetor) {-v.y,v.x};
}

//  04. Calcula a distância entre os pontos p e q.
double distancia(ponto p, ponto q){
    return sqrt(pow(p.x-q.x,2) + pow(p.y-q.y,2));
}

/*  05. Retorna 1 se o coseno do ângulo entre os vetores u e v é 
    positivo e retorna -1 se for negativo e 0 se for nulo. 
    Se u ou v for o vetor nulo, devolve 0. */
int sinal_do_coseno(vetor u, vetor v){
    double produtoInterno = produto_interno(u,v);
    return  produtoInterno > 0
        ?1
        :produtoInterno == 0
            ?0
            :-1;
}

/*  06. Retorna 1 se p, q e r estão em sentido horário e -1 se for
    anti-horário. Se os pontos forem colineares devolva 0. 
    Se dois desses pontos são iguais, devolve 0. */
int sentido(ponto p, ponto q, ponto r){
    double sentido = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y); 
    if (sentido == 0) return sentido;
    return sentido>0? 1: -1;
}

int pertenceSegmento(ponto p, ponto q, ponto r){
    if (
        q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) 
        && q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y)) 
       return 1; 
  
    return 0; 
}
/*  07. Retorna 1 se os interiores dos segmentos se intersectam em
    um único ponto e retorna 0 caso contrário. */
int cruza(segmento s, segmento t){
    int o1 = sentido(s.p, s.q, t.p); 
    int o2 = sentido(s.p, s.q, t.q); 
    int o3 = sentido(t.p, t.q, s.p); 
    int o4 = sentido(t.p, t.q, s.q); 
    // printf("s: ((%f,%f),(%f,%f))\t", s.p.x, s.p.y, s.q.x, s.q.y);
    // printf("t: ((%f,%f),(%f,%f))\t", t.p.x, t.p.y, t.q.x, t.q.y);
    // printf("o1: %d\t o2: %d\t o3: %d\t o4: %d -> ", o1, o2, o3, o4);

    if(
        (s.p.x == t.p.x && s.p.y == t.p.y) || (s.p.x == t.q.x && s.p.y == t.q.y ) 
        || (s.q.x == t.p.x && s.q.y == t.p.y) || (s.q.x == t.q.x && s.q.y == t.q.y)
    ){
        return 0;
    }

    if (o1 != o2 && o3 != o4 && (o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0)){
        return 1;
    }
  
    return 0;
}

float areaTriangulo(triangulo t){
    float area = (t.p.x*(t.q.y-t.r.y) + t.q.x*(t.r.y-t.p.y)+ t.r.x*(t.p.y-t.q.y))/2.0;
    if( area<0 ) return area*-1;
    return area;
}

/*  08. Retorna 1 se o ponto p está no interior do triângulo t
    e retorna 0 caso contrário. */
int dentro(ponto p, triangulo t){
    return sentido(t.p, p, t.r) == sentido(p, t.q, t.r) && sentido(t.p, p, t.r) == sentido(t.p, t.q, p);
}

/*  09. Devolve 1 se um retângulo é vazio e 0 caso contrário. */
/*  Um retângulo é vazio se a extremidade inferior esquerda 
    (ponto ie da struct) se encontra estritamente a direita 
    ou estritamente acima da extremidade superior direita 
    (ponto sd da struct). */
int retangulo_vazio(retangulo r){
    return (r.ie.x > r.sd.x) || (r.ie.y > r.sd.y);
}

/*  10. Devolve o retângulo resultante da intersecção de 
    dois retângulos fechados passados como argumento. 
    Se a intersecção é vazia, qualquer representação 
    de retângulo vazio serve como resposta da funçao! */
retangulo intersecta_ret(retangulo a, retangulo b){

}

// ##############################################################
// OPCIONAL OPCIONAL OPCIONAL OPCIONAL OPCIONAL OPCIONAL OPCIONAL
// ##############################################################
// A partir daqui os exercícios são opcionais (e podem substituir
// alguma implementação de função acima que você não tenha feito).

/* 11. Devolve o ponto em que s e t se intersectam caso cruza(s, t) 
   devolve 1 (ou seja, caso s e t se intersectem em um 
   único ponto no interior dos dois segmentos) e devolve 
   o ponto (0, 0) caso contrário eles não se intersectem em
   um único ponto. */
ponto cruzamento(segmento s, segmento t){}

/* 12. Calcula o ponto que é a projeção ortogonal de p na reta que 
   contém o segmento s. Ou seja, devolve o ponto da reta que 
   contém s que é o mais próximo de p. */
ponto projeta(ponto p, segmento s){
    double dx = s.q.x - s.p.x;
    double dy = s.q.y -  s.p.y;
    double mag = sqrt(dx*dx + dy*dy);
    dx /= mag;
    dy /= mag;

    double lambda = (dx * (p.x - s.p.x)) + (dy * (p.y - s.p.y));
    double x,y;

    x = ((dx * lambda) + s.p.x);
    y = ((dy * lambda) + s.p.y);
    // printf("%.20lf %d ->\t", y, ());
    return (ponto) {
            // 0 == round(x)
            //     ?(double) 0.00000
                ((dx * lambda) + s.p.x),
            y < 0.0000000 && y > -0.000009
                ?(double) 0.000000
                :((dy * lambda) + s.p.y)
        };
}

/* 13. Devolve 1 se o triângulo é degenerado, isto é
   se seus três vértices são colineares e 0 caso contrário. */
int degenerado(triangulo t){
    return !sentido(t.p, t.q, t.r);
}

int is_equal(ponto a, ponto b){
    return a.x == b.x && b.y == a.y;
}
/* 14. Devolve 1 se o interior dos triângulos a e b se 
   intersectam e devolve 0 caso contrário. */
int intersecta_tri(triangulo a, triangulo b){
    // printf("((%f,%f),(%f,%f),(%f,%f)), ((%f,%f),(%f,%f),(%f,%f))", a.p.x, a.p.y, a.q.x, a.q.y, a.r.x, a.r.y, b.p.x, b.p.y, b.q.x, b.q.y, b.r.x, b.r.y);
    return !degenerado(a) && !degenerado(b)  &&
        cruza((segmento) {a.p,a.q}, (segmento) {b.p,b.q})
        || cruza((segmento) {a.q,a.r}, (segmento) {b.p,b.q})
        || cruza((segmento) {a.r,a.p}, (segmento) {b.p,b.q})
        
        || cruza((segmento) {a.p,a.q}, (segmento) {b.q,b.r})
        || cruza((segmento) {a.q,a.r}, (segmento) {b.q,b.r})
        || cruza((segmento) {a.r,a.p}, (segmento) {b.q,b.r})

        || cruza((segmento) {a.p,a.q}, (segmento) {b.p,b.r})
        || cruza((segmento) {a.q,a.r}, (segmento) {b.p,b.r})
        || cruza((segmento) {a.r,a.p}, (segmento) {b.p,b.r})

        || !is_equal(a.p, b.q) && !is_equal(a.p, b.p) && !is_equal(a.p, b.r) && dentro(a.p, b)
        || !is_equal(a.q, b.q) && !is_equal(a.q, b.p) && !is_equal(a.q, b.r) && dentro(a.q, b)
        || !is_equal(a.r, b.q) && !is_equal(a.r, b.p) && !is_equal(a.r, b.r) && dentro(a.r, b)

        || !is_equal(b.p, a.q) && !is_equal(b.p, a.p) && !is_equal(b.p, a.r) && dentro(b.p, a)
        || !is_equal(b.q, a.q) && !is_equal(b.q, a.p) && !is_equal(b.q, a.r) && dentro(b.q, a)
        || !is_equal(b.r, a.q) && !is_equal(b.r, a.p) && !is_equal(b.r, a.r) && dentro(b.r, a);
}