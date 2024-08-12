data Forma = Piedra | Papel | Tijera deriving Show

leGana:: Forma -> Forma -> Bool
leGana Piedra Tijera = True
leGana Papel Piedra = True
leGana Tijera Papel = True
leGana _ _ = False


type Nombre = String
data Jugador = Mano Nombre Forma

ganador:: Jugador -> Jugador -> Maybe Nombre
ganador (Mano n1 f1) (Mano n2 f2) | leGana f1 f2 = Just n1
                                  | leGana f2 f1 = Just n2
                                  | otherwise = Nothing

-------------------------------------------------
mismaForma:: Forma -> Forma -> Bool
mismaForma Piedra Piedra = True
mismaForma Tijera Tijera = True
mismaForma Papel Papel = True
mismaForma _ _ = False


quienJugo:: Forma -> [Jugador] -> [Nombre]
quienJugo _ [] = []
quienJugo f (Mano n1 f1 : xs) | mismaForma f f1 = n1:quienJugo f xs
                              | otherwise = quienJugo f xs

-------------------------------------------------------------------------------------
type Letras = (Char,Char,Char)

type Numeracion = Int

data Matricula = Patente Letras Numeracion deriving (Ord,Eq,Show)

letraValida :: Char -> Bool
letraValida c = 'A' <= c && c <= 'Z'

letrasValidas:: Letras -> Bool
letrasValidas (c1,c2,c3) | letraValida c1 && letraValida c2 && letraValida c3 = True
                         | otherwise = False

matriculaValida:: Matricula -> Bool
matriculaValida (Patente le num) | letrasValidas le && num >= 0 && num <= 999 = True
                                 | otherwise = False

------------------------------------------------------------
filtrar_patentes:: [Matricula] -> Numeracion -> [Matricula]
filtrar_patentes [] _ = []
filtrar_patentes (Patente le num : xs) n | num == n = (Patente le num) : filtrar_patentes xs n
                                         | otherwise = filtrar_patentes xs n
---------------------------------------------------------------
type Titular = String
data Estado = SinDeuda | ConDeuda
data Registro = AgregaReg Matricula Estado Titular Registro | SinRegs

mismoEstado:: Estado -> Estado -> Bool
mismoEstado SinDeuda SinDeuda = True
mismoEstado ConDeuda ConDeuda = True
mismoEstado _ _ = False

consulta:: Registro -> Titular -> Estado -> [Matricula]
consulta SinRegs _ _ = []
consulta (AgregaReg m es1 t1 re) t es | mismoEstado es1 es &&  t1 == t = m: consulta re t es 
                                      | otherwise = consulta re t es 
---------------------------------------------------------------------------------------------------------
--Libro
data Categoria = Literatura | Infantiles | Autoayuda | Comics deriving Show
data Editorial = Altea | Minotauro | Panini deriving Show
type Titulo = String
type Precio = Int

--Agenda
data Marca = Monoblock | Paprika deriving Show
type AnioAgenda = Int
--Precio

--Cuaderno
--marca
--Precio

data ArticulosLibreria = Libro Categoria Editorial Titulo Precio 
                        | Agenda Marca AnioAgenda Precio 
                        | Cuaderno Marca Precio deriving (Show)


librosBaratos :: [ArticulosLibreria] -> Precio -> [ArticulosLibreria]
librosBaratos [] _ = []
librosBaratos (Libro cat ed tit p : ls) precio
  | p <= precio = Libro cat ed tit p : librosBaratos ls precio
  | otherwise = librosBaratos ls precio
librosBaratos (_ : ls) precio = librosBaratos ls precio

mismaEditorial:: Editorial -> Editorial -> Bool
mismaEditorial Altea Altea = True
mismaEditorial Minotauro Minotauro = True
mismaEditorial Panini Panini = True
mismaEditorial _ _ = False


instance Eq ArticulosLibreria where
    (Libro _ edi1 _ p1) == (Libro _ edi2 _ p2) = mismaEditorial edi1 edi2 && p1 == p2
    (Agenda _ ani1 p1) == (Agenda _ ani2 p2) = ani1 == ani2 && p1 == p2
    (Cuaderno _ p1) == (Cuaderno _ p2) = p1 == p2 
    _ == _ = False

--------------------------------------------------------------------------
data Vehiculo = Moto Color Potencia | Auto Color EstiloAuto Potencia deriving (Show)
data Color = Rojo | Azul | Blanco | Gris deriving Show
data EstiloAuto = Sedan | Coupe deriving Show
type Potencia = Int

potencia_vehiculo:: Vehiculo -> Potencia
potencia_vehiculo (Moto _ p) = p
potencia_vehiculo (Auto _ _ p ) = p

instance Ord Vehiculo where
    v1 <= v2 = potencia_vehiculo v1 <= potencia_vehiculo v2

instance Eq Vehiculo where
    (Moto color1 _) == (Moto color2 _) = mismoColor color1 color2
    (Auto color1 _ _) == (Auto color2 _ _) = mismoColor color1 color2
    _ == _ = False



mismoColor:: Color -> Color -> Bool
mismoColor Rojo Rojo = True
mismoColor Azul Azul = True
mismoColor Blanco Blanco = True
mismoColor Gris Gris = True
mismoColor _ _ = False

pintar_coupes::[Vehiculo] -> Color -> [Vehiculo]
pintar_coupes [] _ = []
pintar_coupes(Auto color Coupe p : vs) c | mismoColor color c = Auto c Coupe p : pintar_coupes vs c
                                         | otherwise = pintar_coupes vs c
pintar_coupes(_:vs) c = pintar_coupes vs c
                            
------------------------------------------------------------------------------------------------------
type Ejes = Int
type Altura = Float
type Peso = Int
data Rodado = Automovil Auto|Moto|Bus Ejes Altura|Camion Ejes Altura Peso deriving Show
data Auto = SoloA|ConTrailer Ejes Altura deriving Show

mismaCantEjes :: Rodado -> Ejes -> Bool
mismaCantEjes (Automovil(ConTrailer e' a)) e = (e==e')
mismaCantEjes (Bus e' a) e = (e == e')
mismaCantEjes (Camion e' a p) e = e==e'
mismaCantEjes (Automovil(SoloA)) e = 2==e
mismaCantEjes Moto e = False

cantEjes :: Rodado  -> Int
cantEjes (Automovil (ConTrailer e' a) ) = e'
cantEjes (Bus e' a)  = e'
cantEjes (Camion e' a p)  = e'
cantEjes (Automovil(SoloA))  = 2
cantEjes Moto  = 0

alt :: Rodado ->  Altura
alt (Automovil(ConTrailer e a)) = a
alt (Bus e a)  = a
alt (Camion e a p)  = a
alt (Automovil(SoloA))  = 1.8
alt Moto  = 1.0

instance Eq Rodado
   where
          r1 == r2 =  (mismaCantEjes r1 (cantEjes r2)) ||
                 (((cantEjes r1) >(cantEjes r2)) && ((alt r1)<(alt r2))) ||
                 ((cantEjes r2) >(cantEjes r1) && (alt r2)<(alt r1))


autosConTrailer :: [Rodado]  -> Altura -> [Rodado]
autosConTrailer [] al = []
autosConTrailer ((Automovil(ConTrailer e' a)):xs) al| a>al =  (Automovil(ConTrailer e' a)): (autosConTrailer xs al)
                                                        | otherwise = (autosConTrailer xs al)
autosConTrailer (_:xs)  al =  (autosConTrailer xs al)


dosIguales :: [Rodado] -> Bool
dosIguales [] = False
dosIguales [r] = False
dosIguales (r1:r2:rs) = (r1==r2)||dosIguales(r2:rs)
-------------------
------ ejercicio 2
-------------------
type Ciudad = String
type Distancia = Int
data Tramo = DefinicionDelTramo Ciudad Ciudad Distancia  deriving (Show)
data Viaje = Unico Tramo|ConEscala Tramo Viaje deriving (Show)


tramoPasaPor :: Tramo -> Ciudad -> Bool
tramoPasaPor (DefinicionDelTramo c1 c2 d) c = (c1==c)||(c2==c)

viajePasaPor :: Viaje -> Ciudad -> Bool
viajePasaPor (Unico t) c = tramoPasaPor t c
viajePasaPor (ConEscala t v) c = (tramoPasaPor t c)||(viajePasaPor v c)

distanciaDeTramo :: Tramo -> Distancia
distanciaDeTramo (DefinicionDelTramo c1 c2 d) = d

tramoMasLargo :: Viaje ->Tramo
tramoMasLargo (Unico t) = t
tramoMasLargo (ConEscala t v) | (distanciaDeTramo t) > distanciaDeTramo(tramoMasLargo v) = t
                                  | otherwise = (tramoMasLargo v)

instance Eq Tramo
  where
   DefinicionDelTramo c1 c2 _ == DefinicionDelTramo ci1 ci2 _ = (c1==ci1)&&(c2==ci2)||(c1==ci2)&&(c2==ci1)
