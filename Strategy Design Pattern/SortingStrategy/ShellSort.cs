namespace SortingStrategy
{
    using AbstractSortStrategy;

    /// <summary>
    /// Represents a sorting strategy using the Shell Sort algorithm.
    /// </summary>
    public class ShellSort : AbstractSortStrategy
    {
        /// <summary>
        /// Sorts the given list using the Shell Sort algorithm.
        /// </summary>
        /// <param name="list">The list to be sorted.</param>
        public override void Sort(List<string> list)
        {
            // list.ShellSort(); not-implemented
            Console.WriteLine("ShellSorted list ");
        }
    }
}