//gcc -c '-I'"$PWD/src" seu_prog.c

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
    // x1 -> t.p.x
    // y1 -> t.p.y
    // x2 -> t.q.x
    // y2 -> t.q.y
    // x3 -> t.r.x
    // y3 -> t.r.y
    if(
        (sentido(p, t.q, t.r) == 0 && pertenceSegmento(t.q, p, t.r))
        || (sentido(t.p, p, t.r) == 0 && pertenceSegmento(t.p, p, t.r))
        || (sentido(t.p, t.q, p) == 0 && pertenceSegmento(t.p, p, t.q))
    ){
        return 1;
    }


    float area =  areaTriangulo(t);


    float A1 = areaTriangulo((triangulo){p, t.q, t.r});
    float A2 = areaTriangulo((triangulo){t.p, p, t.r});
    float A3 = areaTriangulo((triangulo){t.p, t.q, p});
    
    // printf("A:%.14f\t A1:%.14f\t A2:%.14f\t A3:%.14f\t",area, A1, A2, A3);
    return area == (A1+A2+A3);
}

/*  09. Devolve 1 se um retângulo é vazio e 0 caso contrário. */
/*  Um retângulo é vazio se a extremidade inferior esquerda 
    (ponto ie da struct) se encontra estritamente a direita 
    ou estritamente acima da extremidade superior direita 
    (ponto sd da struct). */
int retangulo_vazio(retangulo r){
    return (r.ie.x == r.sd.x) || (r.ie.y == r.sd.y);
}

/*  10. Devolve o retângulo resultante da intersecção de 
    dois retângulos fechados passados como argumento. 
    Se a intersecção é vazia, qualquer representação 
    de retângulo vazio serve como resposta da funçao! */
retangulo intersecta_ret(retangulo a, retangulo b){}

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
ponto projeta(ponto p, segmento s){}

/* 13. Devolve 1 se o triângulo é degenerado, isto é
   se seus três vértices são colineares e 0 caso contrário. */
int degenerado(triangulo t){}

/* 14. Devolve 1 se o interior dos triângulos a e b se 
   intersectam e devolve 0 caso contrário. */
int intersecta_tri(triangulo a, triangulo b){}