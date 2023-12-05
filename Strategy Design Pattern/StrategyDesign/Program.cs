namespace Strategy
{   using System;
    using ConcreteStrategy;
    using Context;

    public class Program
    {
        public static void Main(string[] args)
        {
            /// <summary>
            /// Represents the context in which a strategy is executed.
            /// </summary>
            Context context;

            // Three contexts following different strategies
            context = new Context(new ConcreteStrategyA());
            context.ContextInterface();
            context = new Context(new ConcreteStrategyB());
            context.ContextInterface();
            context = new Context(new ConcreteStrategyC());
            context.ContextInterface();

            // Wait for user
            Console.ReadKey();
        }
    }
}