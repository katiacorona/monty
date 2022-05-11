# :snake: Monty Interpreter

Hello! And welcome to our Monty Bytecode Interpreter.

## The Monty language :coconut:

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (like Python does). The language relies on a unique stack, with specific instructions to manipulate.

### Monty byte code files

Files containing Monty byte codes usually have the `.m` extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its arguments:

```
vagrant:monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
vagrant:monty$
```

Monty byte code files can contain blank lines (empty or made of spaces only), and any additional text after the opcode or its required argument is not taken into account:

```
vagrant:monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

## Installation :magic_wand:

To get started, create a new directory in your machine and clone the repository:

```
$ git clone https://github.com/katiacorona/monty.git
```

And compile:

```
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o monty
```

## Usage :arrow_forward:

- `monty <file>`
	- where `file` is the path to the file containing Monty byte code

### Opcode

- `push <int>`
	- pushes an element to the stack
	- where `<int>` is an integer
	
- `pall`
	- prints all the values on the stack, starting from the top of the stack

## Examples

```
vagrant:monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
vagrant:monty$ ./monty bytecodes/00.m
3
2
1
vagrant:monty$
```
