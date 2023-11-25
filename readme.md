## CompactBool

O que é isso? Simples, nem eu sei direito, fiz so pra praticar um pouco.  
O CompactBool é meio que uma alternativa que gasta menos memoria do que o bool, o tipo bool ocupa 1 byte e guarda somente um valor, o CompactBool usa de manipulação de bits para armazenar o maior numero possivel de valores em um byte, mas com isso vem a perca de desempenho, sinceramente nao há motivos de usar isso. Use bitset ao inves disso.  
### Exemplo

```cpp
CompactBool<8> var; //Var tem 8 slots(8 bits), ocupando 1 byte
var.Set(5, true); //Seta o bit 5 como 1(true);

//seria o mesmo que

bool var[8]; //cada tipo bool ocupa 1 byte, como o vetor tem 8, seria 8 bytes.
var[4] = true; //como os vetores começam do 0, o 4 seria a posição 5.
```

### Exemplo 2

```cpp
CompactBool<64> var; //Var assumiu 64 slots/bits(o maximo), ou seja, ocupa 8 bytes, com 64 slots(bits) para escrever
var.Set(64, true); //Seta o slot/bit 64 como 1(true);

//seria o mesmo que

bool var[64]; //cada tipo bool ocupa 1 byte, como o vetor tem 64, seria 64 bytes, 8x a mais que o CompactBool.
var[63] = true; //como os vetores começam do 0, o 63 seria a posição 64.
```

### Exemplo 3

```cpp
CompactBool<31> var; //Voce pode escolher qualquer valor entre 1 e 64 que ira ser usado o tipo mais adequado, uint16, uint32, etc... (caso for usar somente 1, apenas use bool, mesma quantidade de memoria + desempenho melhor). Nesse caso ele assumiu que CompactBool seria um int(32bits).

var.Set(31, true); //Seta o slot/bit 31 como 1(true);
var.Set(32, true); //ele nao seta o bit 32, pois definimos apenas 31
```

### Exemplo 3

```cpp
CompactBool<31> var; //Voce pode escolher qualquer valor entre 1 e 64 que ira ser usado o tipo mais adequado, uint16, uint32, etc... (caso for usar somente 1, apenas use bool, mesma quantidade de memoria + desempenho melhor).

var.Set(31, true); //Seta o slot/bit 31 como 1(true);
var.Set(32, true); //ele nao seta o bit 32, pois definimos apenas 31
```

### Exemplo 4

```cpp
CompactBool<8> var(255); //voce pode passar um valor bruto para o CompactBool, no qual ele ira assumir, por exemplo, 255 em bits ficaria 0b11111111, ou seja, todos slots/bits iriam se iniciar como 1(true);

//fazemos a conversão para int, pois quando usamos 8bits ou menos, é dedicado o tipo uint8(char) para CompactBool, e algumas coisas como o cout entendem que é um caractere
std::cout << "Valor do slot/bit 4: " << (int)var.Get(4); //cout: "Valor do slot/bit 9: 1"
std::cout << "Bin: 0b" << var.Bin(); //cout: "Bin: 0b11111111"
```

### Exemplo 5

```cpp
//nao tem motivos de usar CompactBool se o tamanho for 1 bit, é melhor usar bool
CompactBool<1> var; //tamanho: 1 byte, pois ele ocupa o tamanho que se melhor encaixa nele(uint8), que ocupa 1 byte. 
bool var1; //tamanho: 1 byte

//nesse caso devemos usar o bool, pois a função do CompactBool que é gastar menos memoria não esta sendo cumprida, e ainda perde desempenho. Resumindo, use bool.
//OBS: voce recebera um erro se tentar usar 1 slot no CompactBool
```

### Funções

```cpp
void Set(const uint8_t slot, const bool value)  // Seta o valor no slot/bit escolhido, 1 ou 0(true ou false)
bool Get(const uint8_t slot)                    // Retorna o valor daquele slot/bit, 1 ou 0(true ou false)
Type GetValueBrute()                            // Retorna o valor bruto de CompactBool, exemplo: 255(0B11111111)
void SetValueBrute(const Type value)            // Seta o valor bruto do CompactBool, por exemplo: 255(os primeiros 8 slots serão 1)
std::string GetBin()                            // Retorna o binario do valor bruto. exemplo: 11110011(243)
```