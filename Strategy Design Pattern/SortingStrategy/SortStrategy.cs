namespace AbstractSortStrategy
{
    /// <summary>
    /// Represents an abstract base class for sorting strategies.
    /// </summary>
    public abstract class AbstractSortStrategy
    {
        /// <summary>
        /// Sorts the specified list.
        /// </summary>
        /// <param name="list">The list to be sorted.</param>
        public abstract void Sort(List<string> list);
    }
}