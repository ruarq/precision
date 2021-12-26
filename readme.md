# precision
precision is a microbenchmarking library for C++17 and above.

# How to use it
You can always look into the `example/` folder to get an example, I'm using it to test the API of the library.

Though, precision mainly consists of a list of benchmarks and a function that runs those benchmarks.
Defining a benchmark is really easy:
```cpp
precision::benchmark vector_insert {
	"vector-insert",		// you give it a nice name
	[](auto &ctx) {			// and a function, which will contain what you want to benchmark
		// here you can prepare your benchmark, by allocating memory or whatever you need to do
		// ...
		std::vector<int> v;

		// this loop should contain everything which you want to benchmark
		while (ctx.running())
		{
			// in this case let's test how fast it is to insert a element into a std::vector
			v.insert(v.begin(), 0);
		}
	}
}
```

The easiest way to get a result for that benchmark, is to pass it over to the `precision::main` function:
```cpp
int main()
{
	return preicision::main({ vector_insert });
}
```

This makes defining a bunch of benchmarks really easy:
```cpp
auto benchmarks = {
	precision::benchmark {
		// ...
	},
	precision::benchmark {
		// ...
	},
	precision::benchmark {
		// ...
	}
};
```

and now just pass them to `precision::main()`:
```cpp
int main()
{
	return precision::main(benchmarks);
}
```