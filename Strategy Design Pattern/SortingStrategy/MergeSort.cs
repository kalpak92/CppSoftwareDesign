namespace SortingStrategy
{
    using AbstractSortStrategy;

    /// <summary>
    /// Represents a sorting strategy that uses the merge sort algorithm.
    /// </summary>
    public class MergeSort : AbstractSortStrategy
    {
        /// <summary>
        /// Sorts the given list using the merge sort algorithm.
        /// </summary>
        /// <param name="list">The list to be sorted.</param>
        public override void Sort(List<string> list)
        {
            // list.MergeSort(); not-implemented
            Console.WriteLine("MergeSorted list ");
        }
    }
}