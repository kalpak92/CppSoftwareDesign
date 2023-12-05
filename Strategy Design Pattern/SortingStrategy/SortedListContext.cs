namespace SortedListContext
{
    using AbstractSortStrategy;

    /// <summary>
    /// Represents a context for sorting a list of strings using a specific sorting strategy.
    /// </summary>
    public class SortedListContext
    {
        private List<string> _list = new List<string>();
        private AbstractSortStrategy? _sortStrategy;

        /// <summary>
        /// Sets the sorting strategy to be used for sorting the list.
        /// </summary>
        /// <param name="sortStrategy">The sorting strategy to be set.</param>
        public void SetSortStrategy(AbstractSortStrategy sortStrategy)
        {
            // Allow SortingStrategy to be changed at runtime
            // This is called Dependency Injection
            this._sortStrategy = sortStrategy;
        }

        /// <summary>
        /// Adds a string to the list.
        /// </summary>
        /// <param name="name">The string to be added.</param>
        public void Add(string name)
        {
            _list.Add(name);
        }

        /// <summary>
        /// Sorts the list using the current sorting strategy and displays the sorted results.
        /// </summary>
        public void Sort()
        {
            // Do Nothing but call the implementation using the given strategy
            _sortStrategy?.Sort(_list);

            // Iterate over list and display results
            foreach (string name in _list)
            {
                Console.WriteLine(" " + name);
            }
            Console.WriteLine();
        }
    }
}