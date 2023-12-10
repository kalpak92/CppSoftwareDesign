#include <charconv>
#include <cstdlib>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <iostream>

std::optional<int> to_int( std::string_view sv )
{
   std::optional<int> oi{};
   int i{};

   auto const result = std::from_chars( sv.data(), sv.data() + sv.size(), i );
   
   if( result.ec != std::errc::invalid_argument ) {
      oi = i;
   }

   return oi;
}

int main()
{
   std::string value = "42";

   if( auto optional_int = to_int( value ) )
   {
      std::cout << "Success: " << *optional_int << '\n';
   }
   else
   {
        std::cout << "Failure\n";
   }
}