#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "curso.h"

TEST(comprobarDni,PO1){
    vector<Persona> c;
    Persona p("31885014E");
    c.push_back(p);
    EXPECT_TRUE(p.setDni("31885015E",c));
    EXPECT_FALSE(p.setDni("",c));
    EXPECT_FALSE(p.setDni("31885014E",c));
}  

TEST(comprobarEdad,PO2){
    Persona p;
    EXPECT_FALSE(p.setEdad(10));
    EXPECT_FALSE(p.setEdad(100));
    EXPECT_TRUE(p.setEdad(16));
    EXPECT_TRUE(p.setEdad(24));

}
TEST(ComprobarID,P03){
    vector<Curso> c1;
    BD bd;
    Curso c(1);
    Curso c2(2);
    c1.push_back(c);
    c1.push_back(c2);
    EXPECT_TRUE(c.set_id(3,c1));
    EXPECT_FALSE(c.set_id(1,c1));
    EXPECT_FALSE(c.set_id(2,c1));
     EXPECT_FALSE(c.set_id(0,c1));

}
TEST(ComprobarRecurso,PO4){
    Curso c;
    EXPECT_TRUE(c.set_Recursos("aula"));
    EXPECT_TRUE(c.set_Recursos("equipos informaticos con covid"));
    EXPECT_FALSE(c.set_Recursos(" "));
}


TEST(ComprobarAforo,P05){
    Curso c;
    EXPECT_TRUE(c.set_Aforo(10));
    EXPECT_TRUE(c.set_Aforo(15));
    EXPECT_FALSE(c.set_Aforo(201));
    EXPECT_FALSE(c.set_Aforo(0));
    EXPECT_FALSE(c.set_Aforo(-3));
}
TEST(ComprobarContacto,P06){
    BD bd;
    EXPECT_TRUE(bd.Contacto());
    
}

