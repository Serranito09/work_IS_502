#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "curso.h"

TEST(comprobarDni,PO1){
    vector<Persona> c;
    Persona p("31885014E");
    c.push_back(p);
    EXPECT_TRUE(p.ComprobarDni("31885014E",c));
    EXPECT_FALSE(p.ComprobarDni("3091234B",c));
    EXPECT_FALSE(p.ComprobarDni("4564123B",c));
}  

TEST(ComprobarID,P02){
    vector<Curso> c1;
    Curso c(1);
    Curso c2(2);
    c1.push_back(c);
    c1.push_back(c2);
    EXPECT_TRUE(c.comprobarID(3,&c1));
    EXPECT_FALSE(c.comprobarID(1,&c1));
    EXPECT_FALSE(c.comprobarID(2,&c1));
     EXPECT_FALSE(c.comprobarID(0,&c1));

}



TEST(ComprobarAforo,P03){
    Curso c;
    EXPECT_TRUE(c.comprobarAforo(10));
    EXPECT_TRUE(c.comprobarAforo(15));
    EXPECT_FALSE(c.comprobarAforo(201));
    EXPECT_FALSE(c.comprobarAforo(0));
    EXPECT_FALSE(c.comprobarAforo(-3));
}


TEST(InscribirseCurso,P04){
    BD bd;
    vector<Persona> p;
    vector<Curso>c;
    Curso c1(10);
    Curso c2(6);
    Curso c3(2);
    Persona p1;
    p1.setDni("31885014E");
    Persona p2;
    p2.setDni("30945678A");
    Persona p3;
    p3.setDni("1234567B");
    c.push_back(c1);
    c.push_back(c2);
    c.push_back(c3);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    EXPECT_TRUE(bd.inscribirseCurso(10,"31885014E",&c,&p));
    EXPECT_TRUE(bd.inscribirseCurso(6,"30945678A",&c,&p));;
    EXPECT_FALSE(bd.inscribirseCurso(2,"29867434",&c,&p));
    EXPECT_FALSE(bd.inscribirseCurso(4,"1234567B",&c,&p));
}

TEST(EliminarParticipante,P05){
    vector<Persona>p1;
    BD bd;
    Persona p("31885014E");
    Persona p2("29456734B");
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminarP("31885014E",&p1));
    EXPECT_TRUE(bd.eliminarP("29456734B",&p1));
    EXPECT_FALSE(bd.eliminarP("3456554P",&p1));
     EXPECT_FALSE(bd.eliminarP("2131335E",&p1));

}

TEST(eliminarCurso,P06){
      vector<Curso>p1;
    BD bd;
    Curso p(2);
    Curso p2(5);
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminar(2,&p1));
    EXPECT_TRUE(bd.eliminar(5,&p1));
    EXPECT_FALSE(bd.eliminar(3,&p1));
     EXPECT_FALSE(bd.eliminar(4,&p1));
     EXPECT_FALSE(bd.eliminar(0,&p1));
}


