namespace ConcreteStrategy
{
    using AbstractStrategy;
    using System;

    /// <summary>
    /// Represents a concrete strategy that implements the algorithm defined in the abstract strategy.
    /// </summary>
    public class ConcreteStrategyA : AbstractStrategy
    {
        /// <summary>
        /// Implements the algorithm interface defined in the abstract strategy.
        /// </summary>
        public override void AlgorithmInterface() => Console.WriteLine("Called ConcreteStrategyA.AlgorithmInterface()");
    }

    /// <summary>
    /// Represents another concrete strategy that implements the algorithm defined in the abstract strategy.
    /// </summary>
    public class ConcreteStrategyB : AbstractStrategy
    {
        /// <summary>
        /// Implements the algorithm interface defined in the abstract strategy.
        /// </summary>
        public override void AlgorithmInterface() => Console.WriteLine("Called ConcreteStrategyB.AlgorithmInterface()");
    }

    /// <summary>
    /// Represents yet another concrete strategy that implements the algorithm defined in the abstract strategy.
    /// </summary>
    public class ConcreteStrategyC : AbstractStrategy
    {
        /// <summary>
        /// Implements the algorithm interface defined in the abstract strategy.
        /// </summary>
        public override void AlgorithmInterface() => Console.WriteLine("Called ConcreteStrategyC.AlgorithmInterface()");
    }    
}
