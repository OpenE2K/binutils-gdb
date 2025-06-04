subroutine test( )
  implicit none
  real(16) r1
  complex :: z4 = (3.0, 4.0)
  complex(8) :: z8 = (-1.0, -2.0)
  complex(10) :: z10 = (5.0, -7.0)
  complex(16) :: z16 = (-3.0, 3.0)

  r1 = 1.1234
  print *, r1


  print *, "res = ", z4 + z8 + z10 + z16
end subroutine test

program main
  implicit none

  call test( )
end program main
