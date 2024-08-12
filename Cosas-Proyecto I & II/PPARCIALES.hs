data Nivel = One | Two | Three deriving (Eq, Show)
data NotasDeIngles = EvolucionDelEstudiante String Nivel Int Int Int NotasDeIngles | NoHayMasEstudiantes deriving(Eq,Show)

pasaDeNivel :: NotasDeIngles -> String -> Bool
pasaDeNivel NoHayMasEstudiantes _ = False
pasaDeNivel (EvolucionDelEstudiante nombre nivel nota1 nota2 notaFinal restante) estudiante
    | nombre == estudiante = evaluarNotas nivel nota1 nota2 notaFinal
    | otherwise = pasaDeNivel restante estudiante
    where
        evaluarNotas One n1 n2 nf = (n1 > 7 || n2 > 7) && nf >= 6
        evaluarNotas Two n1 n2 nf = (n1 > 7 || n2 > 7) && nf >= 6
        evaluarNotas Three n1 n2 nf = n1 >= 7 && n2 >= 7 && nf >= 8

-- Definición de notas de ejemplo
notas :: NotasDeIngles
notas = EvolucionDelEstudiante "Juan" One 8 7 6 (EvolucionDelEstudiante "María" Two 7 8 8 NoHayMasEstudiantes)

devolverNivel:: NotasDeIngles -> String -> Maybe Nivel
devolverNivel(EvolucionDelEstudiante n nivel _ _ _ restante) nombre | n == nombre = Just nivel 
                                                                    | otherwise = Nothing


data Color = Rojo | Verde | Azul | Negro | Blanco deriving (Show)

instance Eq Color where
    Rojo == Rojo = True
    Verde == Verde = True
    Azul == Azul = True
    Negro == Negro = True
    Blanco == Blanco = True
    _ == _ = False

mismoColor:: Color -> Color -> Bool
mismoColor Rojo Rojo = True
mismoColor Verde Verde = True
mismoColor Azul Azul = True
mismoColor Negro Negro = True
mismoColor Blanco Blanco = True
mismoColor _ _ = False

--b)
type Nombre = String
type Costo = Int
type Dano = Int
type Resistencia = Int

data CartaMagic = CartaDeTerreno Nombre Color | CartaDeCriatura Nombre Costo Dano Resistencia deriving (Show)

--c)
cuantoDano:: CartaMagic -> Int
cuantoDano(CartaDeTerreno _ _ ) = 0
cuantoDano(CartaDeCriatura _ _ dano _) = dano

--d)

soloTerreno:: [CartaMagic] -> Color -> [Nombre]
soloTerreno [] _ = []
soloTerreno(CartaDeTerreno n c:ns) color | c == color = n: soloTerreno ns color
                                         | otherwise = soloTerreno ns color
soloTerreno(_:ns) color = soloTerreno ns color


data Deporte = Futbol | Basket | Tenis | Valorant | Dota2 deriving (Eq)
type MinJugadores = Int

minimaCantidad:: Deporte -> MinJugadores
minimaCantidad Futbol = 22
minimaCantidad Basket = 10
minimaCantidad Tenis = 2
minimaCantidad Valorant = 10
minimaCantidad Dota2 = 10

--2)
type NombrePersona = String

data PracticoDeporte = AgregaDeporte Deporte NombrePersona PracticoDeporte | Ninguna

deporte:: PracticoDeporte -> Deporte -> NombrePersona -> Bool
deporte Ninguna _ _ = False
deporte (AgregaDeporte d n resto) depo nom | depo == d && nom == n = True
                                           | otherwise= deporte resto depo nom


--Polimorfismo Parapetrico: a ->a (sin restricciones)

--Polimorfismo AdHoc : Eq => a -> [a] (Con restricciones)

--En Haskell, Maybe es un tipo de datos que se usa para representar 
--valores que podrían o no estar presentes. Es como una caja que puede contener algo o estar vacía.
--Por otro lado, Nothing es simplemente la representación de esa caja vacía, mientras que Just valor 
--es la manera de poner un valor dentro de la caja