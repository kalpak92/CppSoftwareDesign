/// <summary>
/// Represents a sorting strategy using the QuickSort algorithm.
/// </summary>
namespace SortingStrategy
{
    using System.Collections.Generic;
    using AbstractSortStrategy;

    /// <summary>
    /// Represents a sorting strategy using the QuickSort algorithm.
    /// </summary>
    public class QuickSort : AbstractSortStrategy
    {
        /// <summary>
        /// Sorts the given list using the QuickSort algorithm.
        /// </summary>
        /// <param name="list">The list to be sorted.</param>
        public override void Sort(List<string> list)
        {
            list.Sort(); // Default is Quicksort
            Console.WriteLine("QuickSorted list ");
        }
    }
}