# `std::variant` : Discriminated Union

## Unions

Unions are rarely used in the client code, and most of the time, they should be avoided.

There’s an existing Core Guideline Rule on that C.183:

> **C.183: Don’t use a union for type punning:**
> It is undefined behaviour to read a union member with a different type from the one with which it was written. 
> Such punning is invisible, or at least harder to spot than using a named cast. Type punning using a union is a source of errors.

There’s also additional issue with unions: they’re very simple and crude. 
You don’t have a way to know what’s the currently used type and what’s more they won’t call destructors of the underlying types.

It’s also worth mentioning that variant types (also called a tagged union, a discriminated union, or a sum type) comes from the functional language world and Type Theory.

Refer : [basic_union.cpp](./basic_union.cpp)
- Unions need a lot of maintenance.
- You have to know which type is active and adequately call destructors/constructors before switching to a new variant.

## Variant

A variant represents one of several alternatives. 

Note that I said *or*: **a variant can contain only one of these three alternatives.** 

It is never several of them, and under usual circumstances, it should never contain nothing. 

For that reason, we call a variant a ***sum type***: **the set of possible states is the sum of possible states of the alternatives.**

- A default variant is also **not empty.** 
- It is initialized to the ***default value of the first alternative.*** In the example, a default variant contains an integer of value 0. 
- Changing the value of a variant is simple: you can just assign new values.

To store the alternatives, **the variant provides just enough internal buffer to hold the largest of the alternatives.** 
- In our case, the largest alternative is the `std::string`, which is usually between 24 and 32 bytes (depending on the used implementation of the Standard Library). 

Refer : [basic_variant.cpp](./basic_variant.cpp)
- You know what’s the currently used type via `index()` or check via `holds_alternative`.
- You can access the value by using `get_if` or `get` (but that might throw `bad_variant_access` exception)
- **Type Safety** - the variant doesn’t allow to get a value of the type that’s not active
- If you don’t initialize a variant with a value, ***then the variant is initialized with the first type***. In that case the first alternative type must have a default constructor.
- No extra heap allocation happens
- You can use a visitor to invoke some action on a currently hold type.
- The variant class calls destructors and constructors of non-trivial types, so in the example, the string object is cleaned up before we switch to new variants.

## When to use
Some possible uses:

- All the places where you might get a few types for a single field: so things like parsing command lines, ini files, language parsers, etc, etc.
- Expressing efficiently several possible outcomes of a computation: like finding roots of equations
- Error handling - for example you can return `variant<Object, ErrorCode>`. If the value is available, then you return Object otherwise you assign some error code.
- State machines
- Polymorphism without `vtables` and inheritance (thanks to visiting pattern)

## Visitors for `std::variant`

The `std::variant` has a handy STL function called `std::visit`. It can call a given "visitor" on all passed variants.

Here's the declaration
```c++
template <class Visitor, class... Variants>  
constexpr visit(Visitor&& vis, Variants&&... vars);
```
And it will call `vis`` on the currently active type of variants.

If you pass only one variant, then you have to have overloads for the types from that variant. If you give two variants, then you have to have overloads for all possible pairs of the types from the variants.

> A visitor is “a callable that accepts every possible alternative from every variant “.