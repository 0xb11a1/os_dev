[bits 32]
mov edx, 0xb8000
mov [edx], byte ' '
mov edx, 0xb8002
mov [edx], byte '_'
mov edx, 0xb8004
mov [edx], byte '_'
mov edx, 0xb8006
mov [edx], byte ' '
mov edx, 0xb8008
mov [edx], byte ' '
mov edx, 0xb800a
mov [edx], byte ' '
mov edx, 0xb800c
mov [edx], byte '_'
mov edx, 0xb800e
mov [edx], byte '_'
mov edx, 0xb8010
mov [edx], byte ' '
mov edx, 0xb8012
mov [edx], byte ' '
mov edx, 0xb8014
mov [edx], byte '_'
mov edx, 0xb8016
mov [edx], byte '_'
mov edx, 0xb8018
mov [edx], byte '_'
mov edx, 0xb801a
mov [edx], byte ' '
mov edx, 0xb80a0
mov [edx], byte '|'
mov edx, 0xb80a2
mov [edx], byte ' '
mov edx, 0xb80a4
mov [edx], byte ' '
mov edx, 0xb80a6
mov [edx], byte '|'
mov edx, 0xb80a8
mov [edx], byte ' '
mov edx, 0xb80aa
mov [edx], byte '|'
mov edx, 0xb80ac
mov [edx], byte ' '
mov edx, 0xb80ae
mov [edx], byte ' '
mov edx, 0xb80b0
mov [edx], byte '|'
mov edx, 0xb80b2
mov [edx], byte '|'
mov edx, 0xb80b4
mov [edx], byte ' '
mov edx, 0xb80b6
mov [edx], byte ' '
mov edx, 0xb80b8
mov [edx], byte ' '
mov edx, 0xb80ba
mov [edx], byte '|'
mov edx, 0xb8140
mov [edx], byte '|'
mov edx, 0xb8142
mov [edx], byte ' '
mov edx, 0xb8144
mov [edx], byte ' '
mov edx, 0xb8146
mov [edx], byte '|'
mov edx, 0xb8148
mov [edx], byte '_'
mov edx, 0xb814a
mov [edx], byte '|'
mov edx, 0xb814c
mov [edx], byte ' '
mov edx, 0xb814e
mov [edx], byte ' '
mov edx, 0xb8150
mov [edx], byte '|'
mov edx, 0xb8152
mov [edx], byte '|'
mov edx, 0xb8154
mov [edx], byte ' '
mov edx, 0xb8156
mov [edx], byte ' '
mov edx, 0xb8158
mov [edx], byte ' '
mov edx, 0xb815a
mov [edx], byte '|'
mov edx, 0xb81e0
mov [edx], byte '|'
mov edx, 0xb81e2
mov [edx], byte ' '
mov edx, 0xb81e4
mov [edx], byte ' '
mov edx, 0xb81e6
mov [edx], byte ' '
mov edx, 0xb81e8
mov [edx], byte ' '
mov edx, 0xb81ea
mov [edx], byte ' '
mov edx, 0xb81ec
mov [edx], byte ' '
mov edx, 0xb81ee
mov [edx], byte ' '
mov edx, 0xb81f0
mov [edx], byte '|'
mov edx, 0xb81f2
mov [edx], byte '|'
mov edx, 0xb81f4
mov [edx], byte ' '
mov edx, 0xb81f6
mov [edx], byte ' '
mov edx, 0xb81f8
mov [edx], byte ' '
mov edx, 0xb81fa
mov [edx], byte '|'
mov edx, 0xb8280
mov [edx], byte '|'
mov edx, 0xb8282
mov [edx], byte ' '
mov edx, 0xb8284
mov [edx], byte ' '
mov edx, 0xb8286
mov [edx], byte ' '
mov edx, 0xb8288
mov [edx], byte ' '
mov edx, 0xb828a
mov [edx], byte ' '
mov edx, 0xb828c
mov [edx], byte ' '
mov edx, 0xb828e
mov [edx], byte ' '
mov edx, 0xb8290
mov [edx], byte '|'
mov edx, 0xb8292
mov [edx], byte '|'
mov edx, 0xb8294
mov [edx], byte ' '
mov edx, 0xb8296
mov [edx], byte ' '
mov edx, 0xb8298
mov [edx], byte ' '
mov edx, 0xb829a
mov [edx], byte '|'
mov edx, 0xb8320
mov [edx], byte '|'
mov edx, 0xb8322
mov [edx], byte ' '
mov edx, 0xb8324
mov [edx], byte ' '
mov edx, 0xb8326
mov [edx], byte ' '
mov edx, 0xb8288
mov [edx], byte '_'
mov edx, 0xb828a
mov [edx], byte ' '
mov edx, 0xb828c
mov [edx], byte ' '
mov edx, 0xb828e
mov [edx], byte ' '
mov edx, 0xb8290
mov [edx], byte '|'
mov edx, 0xb8292
mov [edx], byte '|'
mov edx, 0xb8294
mov [edx], byte ' '
mov edx, 0xb8296
mov [edx], byte ' '
mov edx, 0xb8298
mov [edx], byte ' '
mov edx, 0xb829a
mov [edx], byte '|'
mov edx, 0xb8320
mov [edx], byte '|'
mov edx, 0xb8322
mov [edx], byte '_'
mov edx, 0xb8324
mov [edx], byte '_'
mov edx, 0xb8326
mov [edx], byte '|'
mov edx, 0xb8328
mov [edx], byte ' '
mov edx, 0xb832a
mov [edx], byte '|'
mov edx, 0xb832c
mov [edx], byte '_'
mov edx, 0xb832e
mov [edx], byte '_'
mov edx, 0xb8330
mov [edx], byte '|'
mov edx, 0xb8332
mov [edx], byte '|'
mov edx, 0xb8334
mov [edx], byte '_'
mov edx, 0xb8336
mov [edx], byte '_'
mov edx, 0xb8338
mov [edx], byte '_'
mov edx, 0xb833a
mov [edx], byte '|'

jmp $
[bits 16]
; [bits 16]
times (512*2)-($-$$) db 0 