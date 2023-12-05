namespace Strategy
{
    using System;
    using SortedListContext;
    using SortingStrategy;

    public class Program
    {
        public static void Main(string[] args)
        {
            SortedListContext _studentRecords = new SortedListContext();
            _studentRecords.Add("Samual");
            _studentRecords.Add("Jimmy");
            _studentRecords.Add("Sandra");
            _studentRecords.Add("Vivek");
            _studentRecords.Add("Anna");

            _studentRecords.SetSortStrategy(new QuickSort());   // Configure the sorting behavior from outside, also called Dependency Injection.
            _studentRecords.Sort();

            _studentRecords.SetSortStrategy(new ShellSort());
            _studentRecords.Sort();

            _studentRecords.SetSortStrategy(new MergeSort());
            _studentRecords.Sort();

            // Wait for user
            Console.ReadKey();
        }
    }
}