typedef int wire;
typedef int bool;
typedef struct 
{
  wire **(*garblerIn)(bool *, int);
  wire **(*evaluatorIn)(int);
  wire **(*exec)(wire **, wire **);
} Garbler;
typedef struct 
{
  wire **(*garblerIn)(int);
  wire **(*evaluatorIn)(bool *, int);
  wire **(*exec)(wire **, wire **);
} Evaluator;
typedef struct 
{
  bool d;
} __fln__alice_secretS_bool;
typedef struct 
{
  bool d;
} __fln__alice_secretI_bool;
typedef struct 
{
  Garbler d;
} __fln__garbler_protectedS_Garbler;
typedef struct 
{
  wire d;
} __fln__prepared_functionS_wire;
typedef struct 
{
  Garbler d;
} __fln__garbler_protectedI_Garbler;
__fln__alice_secretS_bool __fln__alice_secretS_bool_intg(bool x)
{
  __fln__alice_secretS_bool y = {.d = x};
  return y;
}

__fln__alice_secretS_bool *__fln__alice_secretS_bool_intg_ptr(bool *x)
{
  __fln__alice_secretS_bool tmp = {.d = *x};
  __fln__alice_secretS_bool *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

bool __fln__alice_secretS_bool_sec(__fln__alice_secretS_bool x)
{
  return x.d;
}

bool *__fln__alice_secretS_bool_sec_ptr(__fln__alice_secretS_bool *x)
{
  return &x->d;
}

__fln__alice_secretI_bool __fln__alice_secretI_bool_intg(bool x)
{
  __fln__alice_secretI_bool y = {.d = x};
  return y;
}

__fln__alice_secretI_bool *__fln__alice_secretI_bool_intg_ptr(bool *x)
{
  __fln__alice_secretI_bool tmp = {.d = *x};
  __fln__alice_secretI_bool *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

bool __fln__alice_secretI_bool_sec(__fln__alice_secretI_bool x)
{
  return x.d;
}

bool *__fln__alice_secretI_bool_sec_ptr(__fln__alice_secretI_bool *x)
{
  return &x->d;
}

__fln__garbler_protectedS_Garbler __fln__garbler_protectedS_Garbler_intg(Garbler x)
{
  __fln__garbler_protectedS_Garbler y = {.d = x};
  return y;
}

__fln__garbler_protectedS_Garbler *__fln__garbler_protectedS_Garbler_intg_ptr(Garbler *x)
{
  __fln__garbler_protectedS_Garbler tmp = {.d = *x};
  __fln__garbler_protectedS_Garbler *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

Garbler __fln__garbler_protectedS_Garbler_sec(__fln__garbler_protectedS_Garbler x)
{
  return x.d;
}

Garbler *__fln__garbler_protectedS_Garbler_sec_ptr(__fln__garbler_protectedS_Garbler *x)
{
  return &x->d;
}

__fln__prepared_functionS_wire __fln__prepared_functionS_wire_intg(wire x)
{
  __fln__prepared_functionS_wire y = {.d = x};
  return y;
}

__fln__prepared_functionS_wire *__fln__prepared_functionS_wire_intg_ptr(wire *x)
{
  __fln__prepared_functionS_wire tmp = {.d = *x};
  __fln__prepared_functionS_wire *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

wire __fln__prepared_functionS_wire_sec(__fln__prepared_functionS_wire x)
{
  return x.d;
}

wire *__fln__prepared_functionS_wire_sec_ptr(__fln__prepared_functionS_wire *x)
{
  return &x->d;
}

__fln__garbler_protectedI_Garbler __fln__garbler_protectedI_Garbler_intg(Garbler x)
{
  __fln__garbler_protectedI_Garbler y = {.d = x};
  return y;
}

__fln__garbler_protectedI_Garbler *__fln__garbler_protectedI_Garbler_intg_ptr(Garbler *x)
{
  __fln__garbler_protectedI_Garbler tmp = {.d = *x};
  __fln__garbler_protectedI_Garbler *y = malloc(sizeof(*y));
  memcpy(y, &tmp, sizeof(*y));
  return y;
}

Garbler __fln__garbler_protectedI_Garbler_sec(__fln__garbler_protectedI_Garbler x)
{
  return x.d;
}

Garbler *__fln__garbler_protectedI_Garbler_sec_ptr(__fln__garbler_protectedI_Garbler *x)
{
  return &x->d;
}

wire **garblerInA(__fln__garbler_protectedS_Garbler alice, __fln__alice_secretS_bool *inputA, int size)
{
  Garbler alice__fln_p = __fln__garbler_protectedS_Garbler_sec(alice);
  bool* inputA__fln_p = __fln__alice_secretS_bool_sec_ptr(inputA);
  wire **out;
  return out;
}

wire **evaluatorInA(__fln__garbler_protectedS_Garbler alice, int size)
{
  Garbler alice__fln_p = __fln__garbler_protectedS_Garbler_sec(alice);
  wire **out;
  return out;
}

wire **execA(__fln__garbler_protectedS_Garbler alice, __fln__prepared_functionS_wire **func, wire **inpt)
{
  wire** func__fln_p = __fln__prepared_functionS_wire_sec_ptr(func);
  Garbler alice__fln_p = __fln__garbler_protectedS_Garbler_sec(alice);
  wire **out;
  return out;
}

__fln__garbler_protectedI_Garbler new_Garbler()
{
  Garbler x;
  return __fln__garbler_protectedI_Garbler_intg(x);
}

__fln__alice_secretI_bool *int2bitsA(int x)
{
  bool *x;
  return __fln__alice_secretI_bool_intg_ptr(x);
}

wire **garblerInB(Evaluator bob, int size)
{
  wire **out;
  return out;
}

wire **evaluatorInB(Evaluator bob, bool *inputB, int size)
{
  wire **out;
  return out;
}

wire **execB(Evaluator bob, wire **func, wire **inpt)
{
  wire **out;
  return out;
}

Evaluator new_Evaluator()
{
  Evaluator x;
  return x;
}

bool *int2bitsB(int x)
{
  bool *x;
  return x;
}

wire *mux(wire *x, wire *y, wire *c)
{
  return xor(and(c, xor(x, y)), y);
}

wire **mux8(wire **ws)
{
  wire *x = *ws;
  wire *y = (*ws) + 8;
  wire *c = (*ws) + 16;
  wire **ret;
  for (int i = 0; i < 8; i++)
  {
    ret[i] = mux(x + i, y + i, c);
  }

  return ret;
}

void main1()
{
  __fln__garbler_protectedS_Garbler alice;
  alice = new_Garbler();
  __fln__alice_secretS_bool *inputA;
  inputA = int2bitsA(0x01AA);
  wire **wsA = garblerInA(alice, inputA, 8);
  wire **wsB = evaluatorInA(alice, 8);
  wire **ws;
  for (int i = 0; i < 8; i++)
  {
    *ws[i] = *wsA[i];
    *ws[i + 8] = *wsB[i];
  }

  *ws[16] = garblerInA(alice, inputA + 8, 1);
  wire **os = execA(alice, mux8, ws);
  bool *ret;
  for (int i = 0; i < 8; i++)
    evaluatorOut(os[i]);

  free(os);
}

void main2()
{
  Evaluator bob;
  bob = new_Evaluator();
  bool *inputB;
  inputB = int2bitsB(0xBB);
  wire **wsA = garblerInB(bob, 8);
  wire **wsB = evaluatorInB(bob, inputB, 8);
  wire **ws;
  for (int i = 0; i < 8; i++)
  {
    *ws[i] = *wsA[i];
    *ws[i + 8] = *wsB[i];
  }

  *ws[16] = garblerInB(bob, 1);
  wire **os = execB(bob, mux8, ws);
  bool *ret;
  for (int i = 0; i < 8; i++)
    ret[i] = evaluatorOut(os[i]);

  printf("%d", bits2int(ret));
  free(os);
}

