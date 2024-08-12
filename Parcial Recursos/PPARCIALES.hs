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


--Parciales Viejos
--2023 Tema A

--Ladrillo
data TipoLadrillo = Ceramico | Hormigon | Tradicional deriving(Show)
data UsoLadrillo = Pared | Techo deriving(Show)
type Precio = Int

--Vigueta
data MaterialViga = Hierro | Madera deriving(Show)
type Largo = Float

--Cemento
data MarcaCemento = Minetti | Lomanegra deriving(Show)


data MaterialesConstruccion = Ladrillo TipoLadrillo UsoLadrillo Precio 
                            | Vigueta Largo MaterialViga Precio
                            | Cemento MarcaCemento Precio deriving(Show)


ladrillosDeMenorPrecio :: [MaterialesConstruccion] -> Int -> [MaterialesConstruccion]
ladrillosDeMenorPrecio [] _ = []
ladrillosDeMenorPrecio (Ladrillo tl ul pc:lm) n
    | pc < n = Ladrillo tl ul pc : ladrillosDeMenorPrecio lm n
    | pc == n = Ladrillo tl ul pc : ladrillosDeMenorPrecio lm n
    | otherwise = ladrillosDeMenorPrecio lm n
ladrillosDeMenorPrecio (_:lm) n = ladrillosDeMenorPrecio lm n

-- Definición de algunos materiales de construcción
ladrillo1 = Ladrillo Ceramico Pared 500
ladrillo2 = Ladrillo Hormigon Techo 600
ladrillo3 = Ladrillo Tradicional Pared 450
vigueta1 = Vigueta 5.2 Hierro 800
cemento1 = Cemento Minetti 300

-- Lista de materiales de construcción
materiales = [ladrillo1, ladrillo2, ladrillo3, vigueta1, cemento1]

-- Probando la función ladrillosDeMenorPrecio
ejemplo = ladrillosDeMenorPrecio materiales 550

--instance Eq MaterialesConstruccion where
    --(Ladrillo tipol _ pl) == (Ladrillo tipol2 _ pl2) = tipol == tipol2 && pl == pl2
    --(Vigueta largo _ preciovig) == (Vigueta largo1 _ preciovig1) = largo == largo1 && preciovig == preciovig1
   -- (Cemento marcace _) == (Cemento marcace1 _) = marcace == marcace1

-- Igualdad para el tipo TipoLadrillo
instance Eq TipoLadrillo where
    Ceramico == Ceramico = True
    Hormigon == Hormigon = True
    Tradicional == Tradicional = True
    _ == _ = False

-- Igualdad para el tipo UsoDeLadrillo
instance Eq UsoLadrillo where
    Pared == Pared = True
    Techo == Techo = True
    _ == _ = False

-- Igualdad para el tipo MaterialViga
instance Eq MaterialViga where
    Hierro == Hierro = True
    Madera == Madera = True
    _ == _ = False

-- Igualdad para el tipo MarcaCemento
instance Eq MarcaCemento where
    Minetti == Minetti = True
    Lomanegra == Lomanegra = True
    _ == _ = False

-- Igualdad para el tipo MaterialesConstruccion
instance Eq MaterialesConstruccion where
    (Ladrillo tipoL1 usoL1 precio1) == (Ladrillo tipoL2 usoL2 precio2) =
        tipoL1 == tipoL2 && precio1 == precio2
    (Vigueta largo1 material1 precio1) == (Vigueta largo2 material2 precio2) =
        largo1 == largo2 && material1 == material2
    (Cemento marca1 precio1) == (Cemento marca2 precio2) =
        marca1 == marca2
    _ == _ = False

--------

--Libro
data Categoria = Literatura | Infantiles | AutoAyuda | Comics deriving(Show)
data Editorial = Altea | Minotauro | Panini deriving(Show)
type Titulo = String
--type Precio = Int

--Agenda
data Marca = Monoblock | Paprika deriving(Show)
type AnioAgenda = Int
--type Precio = Int

--Cuaderno
--data Marca = Monoblock | Paprika
--type Precio = Int

data ArticulosLibreria = Libro Categoria Editorial Titulo Precio
                        | Agenda Marca AnioAgenda Precio
                        | Cuaderno Marca Precio deriving(Show)


librosBaratos :: [ArticulosLibreria] -> Precio -> [ArticulosLibreria]
librosBaratos [] _ = []
librosBaratos (Libro cat edi tit pre:ls) p
    | pre <= p = Libro cat edi tit pre : librosBaratos ls p
    | otherwise = librosBaratos ls p
librosBaratos (_:ls) p = librosBaratos ls p

instance Eq Editorial where
    Altea == Altea = True
    Minotauro == Minotauro = True
    Panini == Panini = True
    _ == _ = False

instance Eq ArticulosLibreria where
    (Libro _ edit _ pl) == (Libro _ edit1 _ pl1) = edit == edit1 && pl == pl1
    (Agenda _ anio pra) == (Agenda _ anio1 pra1) = anio == anio1 && pra == pra1
    (Cuaderno _ pc) == (Cuaderno _ pc1) = pc == pc1
    _ == _ = False

valorODefault :: Int -> Maybe Int -> Int 
valorODefault i Nothing = i 
valorODefault _ (Just x) = x

data EstadoHojas = MuchasQuemadas | PocasQuemadas | Saludables deriving (Show, Eq)

data RegistroPlanta = DatoPlanta EstadoHojas Int Int Int Int RegistroPlanta
                    | NoDato deriving (Show)

trasplantar :: RegistroPlanta -> Int -> Bool
trasplantar NoDato _ = False
trasplantar (DatoPlanta estado altura _ _ edad _) edadMinima
    | edad >= edadMinima && ((estado == PocasQuemadas || estado == Saludables) && altura > 40) = True
    | edad >= edadMinima && (estado == MuchasQuemadas && altura < 10) = True
    | otherwise = False

devolverEstado :: RegistroPlanta -> Int -> Maybe EstadoHojas
devolverEstado NoDato _ = Nothing
devolverEstado (DatoPlanta estado _ _ _ edad _) edadMinima
    | edad >= edadMinima = Just estado
    | otherwise = Nothing


---
type Tituloo = String
type Rank = Int
data Estado = Reproducido | SinReproducir deriving (Show)
type Duracion = Int

data Playlist = Tema Tituloo Rank Estado Duracion Playlist | SinTemas deriving(Show)

segundos_restantes:: Playlist -> Rank -> Duracion 
segundos_restantes SinTemas _ = 0
segundos_restantes(Tema _ _ SinReproducir duracion ps) r = duracion + segundos_restantes ps r
segundos_restantes(Tema _ rank Reproducido _ ps) r 
    | rank >= r = segundos_restantes ps rank
    | otherwise = segundos_restantes ps r 

-- Supongamos que tienes una playlist llamada "miPlaylist" y quieres calcular los segundos restantes
-- para las canciones con un ranking mayor o igual a 3
-- Definición de la playlist "miPlaylist"
-- let miPlaylist = Tema "Cancion1" 5 SinReproducir 180 (Tema "Cancion2" 4 Reproducido 200 (Tema "Cancion3" 2 SinReproducir 150 SinTemas))
-- Calculando los segundos restantes
-- segundosRestantes miPlaylist 3

estadoDelTema :: Tituloo -> Playlist -> Maybe Estado
estadoDelTema _ SinTemas = Nothing
estadoDelTema titulo (Tema tit _ estado _ ps)
    | titulo == tit = Just estado
    | otherwise = estadoDelTema titulo ps


----
data Forma = Piedra | Papel | Tijera

le_gana:: Forma -> Forma -> Bool
le_gana Piedra Tijera = True
le_gana Piedra Piedra = False -- Empate
le_gana Piedra Papel = False
le_gana Papel Piedra = True
le_gana Papel Papel = False --Empate
le_gana Papel Tijera = False
le_gana Tijera Papel = True
le_gana Tijera Tijera = False --Empate
le_gana Tijera Piedra = False

type Nombree = String

data Jugador = Mano Nombree Forma

ganador:: Jugador -> Jugador -> Maybe Nombree
ganador(Mano j1 f1)(Mano j2 f2) |le_gana f1 f2  = Just j1
                                |le_gana f2 f1  = Just j2
                                |otherwise = Nothing

