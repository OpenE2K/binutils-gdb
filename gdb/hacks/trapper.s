.global _start

_start:
        # .dword 0x0
        .dword 0x0dc0c08004000001
self:
        disp %ctpr1, self
next:   
        ct %ctpr1
