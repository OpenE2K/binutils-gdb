const char *new_sd_get_seats (void);
__asm__ (".symver new_sd_get_seats,sd_get_seats@LIBSYSTEMD_209");

const char *(*sd_get_seats_p) (void) = new_sd_get_seats;

const char *sd_get_seats (void)
{
  if (sd_get_seats_p == &sd_get_seats)
    return "LOOP";
  return (*sd_get_seats_p) ();
}
