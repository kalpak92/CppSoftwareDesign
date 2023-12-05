namespace Context
{
    using AbstractStrategy;

    /// <summary>
    /// Represents the context in the strategy design pattern.
    /// </summary>
    public class Context
    {
        /// <summary>
        /// Represents an abstract strategy.
        /// </summary>
        AbstractStrategy strategy;

        /// <summary>
        /// Initializes a new instance of the <see cref="Context"/> class with the specified strategy.
        /// </summary>
        /// <param name="strategy">The strategy to be used by the context.</param>
        public Context(AbstractStrategy strategy) => this.strategy = strategy;

        /// <summary>
        /// Executes the algorithm using the current strategy.
        /// </summary>
        public void ContextInterface() => strategy.AlgorithmInterface();
    }
}