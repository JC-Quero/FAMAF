{-# LANGUAGE NPlusKPatterns #-}

--Ejercicio 1
data Carrera = Matematica | Fisica | Computacion | Astronomia 
    deriving Eq

titulo:: Carrera -> String 
titulo carrera | carrera == Matematica = "Licenciatura en Matematica"
               | carrera == Fisica = "Licenciatura en Fisica"
               | carrera == Computacion = "Licenciatura en Computacion"
               | carrera == Astronomia = "Licenciatura en Astronomia"

data NotaBasica = Do | Re | Mi | Fa | Sol | La | Si
    deriving (Eq, Ord, Bounded, Show)

cifradoAmericano:: NotaBasica -> Char
cifradoAmericano Do = 'C'
cifradoAmericano Re = 'D'
cifradoAmericano Mi = 'E'
cifradoAmericano Fa = 'F'
cifradoAmericano Sol = 'G'
cifradoAmericano La = 'A'
cifradoAmericano Si = 'B'

--2
--a)
--ghci> Do <= Re
--True

--ghci> Fa `min` Sol
--Fa


--3) Recordamos el ejercicio de Sumatoria   
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria(x:xs) = x + sumatoria xs

sumatoriaAdHoc:: Num a => [a] -> a
sumatoriaAdHoc [] = 0
sumatoriaAdHoc(x:xs) = x + sumatoriaAdHoc xs

--a)

minimoElemento:: Ord a => [a] -> a
minimoElemento[x]= x
minimoElemento (x:xs) = x `min` minimoElemento xs

--ghci> minimoElemento [3,1,2,5,6,10]
--1

--b)
minimoElemento' :: (Bounded a, Ord a) => [a] -> a  
minimoElemento'[]= minBound 
minimoElemento'[x] = x
minimoElemento'(x:xs)= x `min` minimoElemento' xs

--ghci> minimoElemento' ([1,5,10]::[Int])
--1

--c)
--ghci> minimoElemento [Fa,La,Sol,Re,Fa]
--Re

--4)

--Sinonimos de tipo
type Altura = Int
type NumCamiseta = Int

--Tipos algebraicos sin Parametros (aka enumerados)
data Zona = Arco | Defensa | Mediocampo | Delantera deriving(Show, Eq)
data TipoReves = DosManos | UnaMano deriving Show
data Modalidad = Carretera | Pista | Monte | BMX deriving Show
data PiernaHabil = Izquierda | Derecha deriving Show

--Sinonimo
type ManoHabil = PiernaHabil

--Deportista es un tipo algebraico con constuctores parametricos
data Deportista = Ajedrecista --Constructor sin argumentos
                |Ciclista Modalidad   --Constructor con un argumento
                |Velocista Altura      --Constructor con un argumento
                |Tenista TipoReves ManoHabil Altura --Constructor con tres argumentos
                |Futbolista Zona NumCamiseta PiernaHabil Altura deriving Show
                    
               

--b) ghci> :t Ciclista
--Ciclista :: Modalidad -> Deportista

--c)
contar_velocistas :: [Deportista] -> Int
contar_velocistas [] = 0  
contar_velocistas (x:xs) = contarVelocista x + contar_velocistas xs
  where contarVelocista (Velocista _) = 1  
        contarVelocista _ = 0  

--ghci> contar_velocistas [Ciclista Carretera, Ajedrecista, Velocista 180, Velocista 170]
--2

--d)
contar_futbolistas :: [Deportista] -> Zona -> Int
contar_futbolistas [] _ = 0
contar_futbolistas (Futbolista z _ _ _ : xs) z' 
    | z == z' = 1 + contar_futbolistas xs z'
    | otherwise = contar_futbolistas xs z'
contar_futbolistas (_:xs) z = contar_futbolistas xs z

--ghci> contar_futbolistas [Futbolista Defensa 8 Derecha 174, Velocista 180, Futbolista Defensa 5 Izquierda 180] Defensa
--2

contar_futbolistas':: [Deportista] -> Zona -> Int
contar_futbolistas' xs z = length (filter misma_zona xs)
    where
        misma_zona (Futbolista zona _ _ _) = (zona == z)
        misma_zona _ = False
--ghci> contar_futbolista' [Futbolista Defensa 8 Derecha 174, Velocista 180, Futbolista Defensa 5 Izquierda 180] Defensa
--2

--5

--a)
sonidoNatural :: NotaBasica -> Int
sonidoNatural Do = 0
sonidoNatural Re = 2
sonidoNatural Mi = 4
sonidoNatural Fa = 5
sonidoNatural Sol = 7
sonidoNatural La = 9
sonidoNatural Si = 11

--b)
data Alteracion = Bemol | Natural | Sostenido 
    

--c)
data NotaMusical = Nota NotaBasica Alteracion    


--d)
sonidoCromatico :: NotaMusical -> Int
sonidoCromatico (Nota n Natural) = sonidoNatural n
sonidoCromatico (Nota n Bemol) = sonidoNatural n - 1
sonidoCromatico (Nota n Sostenido) = sonidoNatural n + 1

--ghci> sonidoCromatico (Nota Sol Bemol)
--6

--e)
instance Eq NotaMusical where
    n1 == n2 = sonidoCromatico n1 == sonidoCromatico n2

instance Ord NotaMusical where
    n1 <= n2 = sonidoCromatico n1 <= sonidoCromatico n2


--f)

--a)

primerElemento:: [a] -> Maybe a
primerElemento [] = Nothing
primerElemento (x:_)= Just x

--ghci> primerElemento [1,2,3,4,5]
--Just 1

--ghci> primerElemento []
--Nothing

--7)
data Cola = VaciaC | Encolada Deportista Cola deriving Show


atender :: Cola -> Maybe Cola 
atender VaciaC = Nothing
atender (Encolada _ c) = Just c

--ghci> atender c
--Just (Encolada (Velocista 182) VaciaC)

--b)

ejemploE:: Cola
ejemploE = Encolada (Velocista 182) VaciaC

encolar :: Deportista -> Cola -> Cola
encolar d VaciaC           = Encolada d VaciaC            
encolar d (Encolada x c)   = Encolada x (encolar d c)  

--ghci> encolar Ajedrecista ejemploE
--Encolada (Velocista 182) (Encolada Ajedrecista VaciaC)

ejemploB:: Cola
ejemploB = Encolada (Futbolista Defensa 3 Derecha 180) VaciaC

--c)

busca:: Cola -> Zona -> Maybe Deportista    
busca VaciaC z = Nothing
busca (Encolada (Futbolista zona n p a ) cola) z | (zona == z) = Just (Futbolista zona n p a) 
                                            |otherwise = busca cola z

--ghci> busca ejemploB Defensa
--Just (Futbolista Defensa 3 Derecha 180)

--8)

data ListaAsoc a b = Vacia | Nodo a b (ListaAsoc a b) deriving Show
type Diccionario = ListaAsoc String String
type Padron      = ListaAsoc Int String
type Guia = ListaAsoc String Int

--b)
la_long :: ListaAsoc a b -> Int
la_long Vacia = 0
la_long (Nodo a b (xs)) = 1 + la_long xs

--2) 
la_concat :: ListaAsoc a b -> ListaAsoc a b -> ListaAsoc a b
la_concat xs Vacia = xs
la_concat Vacia ys = ys
la_concat (Nodo a b xs) ys = (Nodo a b(la_concat xs ys))

--3)
la_agregar :: Eq a => ListaAsoc a b -> a -> b -> ListaAsoc a b
la_agregar Vacia clave dato = Nodo clave dato Vacia
la_agregar (Nodo a b xs) clave dato | (a == clave) = Nodo a dato xs
                                    | otherwise  = Nodo a b (la_agregar xs clave dato)

--4)
la_pares :: ListaAsoc a b -> [(a, b)]
la_pares Vacia = []
la_pares (Nodo a b xs) = (a, b):la_pares xs

--5) 
la_busca :: Eq a => ListaAsoc a b -> a -> Maybe b
la_busca Vacia clave = Nothing
la_busca (Nodo a b xs) clave | (a == clave) = Just b
                             | otherwise  = la_busca xs clave

--6)
la_borrar :: Eq a => a -> ListaAsoc a b -> ListaAsoc a b
la_borrar clave Vacia = Vacia
la_borrar clave (Nodo a b xs) | (a == clave) = xs
                              | otherwise  = Nodo a b (la_borrar clave xs)

