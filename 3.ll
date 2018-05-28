
define void @ola() #0 {
entry:
  %a = alloca i32, align 4
  store i32 1, i32* %a, align 4
  ret void
}