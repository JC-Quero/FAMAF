data ArtistaMusical = Cantante Registro TipoCanto Trayecto | Instrumentista Instrumento Trayecto 

data Registro = Soprano | Contralto | Tenor | Baritono | Bajo 
data TipoCanto = Solista | Coral
data Instrumento = Violin | Clarinete | Trompeta | Timbales

type Trayecto = Int

trayectoria_musical:: ArtistaMusical -> Trayecto
trayectoria_musical (Cantante _ _ t) = t 
trayectoria_musical (Instrumentista _ t) = t


-- Instancia de Eq para ArtistaMusical
instance Eq ArtistaMusical where
    (Cantante _ _ trayecto1) == (Cantante _ _ trayecto2) = trayecto1 == trayecto2
    (Instrumentista _ trayecto1) == (Instrumentista _ trayecto2) = trayecto1 == trayecto2
    _ == _ = False

-- Instancia de Ord para ArtistaMusical
instance Ord ArtistaMusical where
  a1 <= a2 = trayectoria_musical a1 <= trayectoria_musical a2



mismoCantante:: ArtistaMusical -> ArtistaMusical -> Bool
mismoCantante (Cantante _ Solista _ ) (Cantante _ Solista _) = True
mismoCantante (Cantante _ Coral _ ) (Cantante _ Coral _) = True
mismoCantante _ _ = False


mismoRegistro:: Registro -> Registro -> Bool
mismoRegistro Tenor Tenor = True
mismoRegistro Soprano Soprano = True
mismoRegistro Contralto Contralto = True
mismoRegistro Bajo Bajo = True
mismoRegistro Baritono Baritono = True
mismoRegistro _ _ = False

buscarSolistas :: [ArtistaMusical] -> Registro -> [ArtistaMusical]
buscarSolistas [] _ = []
buscarSolistas (Cantante reg Solista trayecto : as) r
    | mismoRegistro reg r  = Cantante reg Solista trayecto : buscarSolistas as r
    | otherwise = buscarSolistas as r
buscarSolistas (_:as) r = buscarSolistas as r

-----------------------------------------------------------------------------------------------
--Planta
data TipoPlanta = PlenoSol | MediaSombra | Floral | Frutal deriving Show
data Ubicacion = Exterior | Interior deriving Show
data Agua =  MuyResistente | Resistente | NadaResistente deriving Show

type Precio = Int

--Bolsa Semilla
data TipoSemilla = Hortaliza | Aromatica | Cesped deriving Show
type Peso = Int
--Precio

--Maceta
data TipoMaceta = Terracota | Fibrocemento | Plastico deriving Show
data Forma = Cuadrada | Redonda deriving Show
--precio

data ProductoVivero = Planta TipoPlanta Ubicacion Agua Precio 
                    | Semilla TipoSemilla Peso Precio 
                    | Maceta TipoMaceta Forma Precio 
                    deriving Show


mismo_tipo_planta:: TipoPlanta -> TipoPlanta -> Bool
mismo_tipo_planta PlenoSol PlenoSol = True
mismo_tipo_planta MediaSombra MediaSombra = True
mismo_tipo_planta Floral Floral = True
mismo_tipo_planta Frutal Frutal = True
mismo_tipo_planta _ _ = False

misma_ubi:: Ubicacion -> Ubicacion -> Bool
misma_ubi Exterior Exterior = True
misma_ubi Interior Interior = True
misma_ubi _ _ = False

misma_maceta:: TipoMaceta -> TipoMaceta -> Bool
misma_maceta Terracota Terracota = True
misma_maceta Fibrocemento Fibrocemento = True
misma_maceta Plastico Plastico = True
misma_maceta _ _ = False

cuantas_plantas::[ProductoVivero] -> TipoPlanta -> Int
cuantas_plantas [] _ = 0
cuantas_plantas(Planta pl _ _ _ :pv) tp | mismo_tipo_planta pl tp = 1 + cuantas_plantas pv tp   
                                        | otherwise = cuantas_plantas pv tp
cuantas_plantas(_:pv) tp = cuantas_plantas pv tp

instance Eq ProductoVivero where
    (Planta tp1 ubi1 _ _) == (Planta tp2 ubi2 _ _) = mismo_tipo_planta tp1 tp2 && misma_ubi ubi1 ubi2
    (Semilla _ pe1 pre1) == (Semilla _ pe2 pre2) = pe1 == pe2 && pre1 == pre2
    (Maceta f1 _ _ ) == (Maceta f2 _ _) = misma_maceta f1 f2
    _ == _ = False

data RegistroPlanta =  DatoPlanta  EstadoHojas Int Int Int Int RegistroPlanta | NoDato deriving (Show,Eq,Ord)
data EstadoHojas = MuchasQuemadas | PocasQuemadas | Saludables deriving (Show,Ord,Eq)

cumpleCondicion :: EstadoHojas -> Int -> Int -> Bool
cumpleCondicion PocasQuemadas altura _ = altura > 40
cumpleCondicion Saludables altura _ = altura > 40
cumpleCondicion MuchasQuemadas _ hojasTotales = hojasTotales < 10

transplantar:: RegistroPlanta -> Int -> Bool 
transplantar NoDato _ = False
transplantar (DatoPlanta estado altura hojasTotales _ edad resto) edadMin
    |edad <= edadMin && cumpleCondicion estado altura hojasTotales = True
    |otherwise = transplantar resto edadMin

devolverEstado:: RegistroPlanta -> Int -> Maybe EstadoHojas
devolverEstado NoDato _ = Nothing
devolverEstado (DatoPlanta estado _ _ _ edad resto) edadMin
    | edad >= edadMin = Just estado
    | otherwise = devolverEstado resto edadMin