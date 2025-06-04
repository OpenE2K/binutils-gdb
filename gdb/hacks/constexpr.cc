
class my_string_view
{
public:
  constexpr my_string_view (const char *__str)
  : _M_str (__str)
  { }

  const char *_M_str;
};

int
main ()
{
  constexpr const char *fika = "fika";
  constexpr my_string_view sv1 = {fika};
  //constexpr my_string_view sv2 (fika);

  static_assert (sv1._M_str == fika, "Checkpoint #1");
  //static_assert (sv2._M_str == fika, "Checkpoint #2");

  return 0;
}
