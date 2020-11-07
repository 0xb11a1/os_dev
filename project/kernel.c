void kmain();


// #define true=1;
// #define false=0;

void entry(){
    kmain();
}




// from the video - still need some work - does work as expected
// void print(char* message){
//     char *p_video_buffer = (char*) 0xb8000;
//     char *p_next_char = message;
//     while(*p_next_char){
//         *p_video_buffer = *p_next_char;
//         p_next_char++;
//         p_video_buffer +=2 ; 
//     }
// }



// to run it : 
// TODO:
// change it to make file 
// on tochiba change it to network boot - buy ethernet cable 
// Usage: 
// gcc -m32 -ffreestanding -c kernel.c -o kernel.o -fno-pie
// ld -o kernel.bin -Ttext 0x7e00 kernel.o -m elf_i386 --oformat binary
// cat test.bin kernel.bin >  all.bin 
// sudo dd if=all.bin of=/dev/sdc bs=512 count=20 conv=notrunc ; echo "d\nn\np\n\n\n\na\nw\n" | sudo fdisk /dev/sdc

// wait some time (still random based on the cpu speed)
void sleep(){
    for(int i = 0 ; i < 100000000; i++){
        int a = 9;
        int b = a+5 ;
    }
    
    
}
// clear screen (just for char now not colors)
void cls(){
    char *base_video = (char*) 0xb8000;
    int i = 0;
    // edit the range -> 160*25/2
    while(i< 160*25/2){
        *base_video  = ' ';
        base_video +=2 ;
        i++;
    }
}

// print larg art on the screen using '!' as new line indicator 
void print_art(char *art){
    char *msg = art;
    char *base_video = (char*) 0xb8000;
    int i ; 
    while(*msg){
        if(*msg == '!'){
            base_video += 160;
            i = 0 ;
            msg++;
            continue ; 
        }
        char *curr;
        curr = base_video +i;
        *curr = *msg;
        
        msg++;
        i+=2 ; 
    }
}


// charater size :
// width = 80
// hight = 25 

// kernal main function
void kmain(){

    // animated acsii-art just 4 frame due to memory restriction 
    while(1){

        print_art("                                        !                                        !                                        !                   MBM   .NM:           !                  5B Bi  B2rB           !                  iG Su .B :r           !                  .B:JBOMF Br           !                7BB:       uMMP         !              iBu             FB7       !             7B                 B0      !            .B,ir::,,:.  :i::.   GB     !            XO rrYri:r.  1XXZUUF. B7    !            8P                    Br    !            :B                   .B.    !             XB                 :Bj     !              :MX.            .0Br      !               BBqBMFrULY7L7NGB7        !              LXB. .,:rLi7BLB           !             ,MiB        :M B           !             BUB:        ZvuU           !          ,i;B1B         B B            !         .BB2LB:        iB,B5r          !             MB         8Bi:Ei          !");
        sleep();
        cls();
        print_art("                                        !                                        !                                        !                  vi    .7.             !                 BJB2  :BkB             !                .B :0  Bi S.            !                 S2 BrrB :E             !               .5BN rL7r rBUi           !              0BX          ikBN         !             Bv               BB:       !            B:                 .B,      !           YX,MEEOZ8S. .kGUFPMG .B      !           B,    ..           .  B.     !           B;                   ,B      !           :B.                  BY      !            :B7               iB7       !              BB7i, .       7XOi        !              N,BNY1BEEB1BMBB.          !             UNLB        M:07           !             BrB.        B Bi           !          BBOj8Z        :B B            !          US:rB:        L1PY            !             2B         M2S1B           !");
        sleep();
        cls();
        print_art("                                        !                                        !                                        !                .      .                !               iMBU   MMB               !               B :B  LB Xr              !               5S 8, EB E               !               ,B.UBMBi BSr             !             :BBi        ;1MBi          !            PG,             :BB         !           05                 iB        !          2B i7LvLri  .UrYJ7LY 2B       !          B: rYLYv7i  .,, . ..  B       !          Bi                    B       !          UB                   G5       !           8M                ,BN        !            i0q.           .NBL         !             :M8B0YkXEZ0SMXB7           !             2iB7  .:.  :B X            !             B7B        iB:5            !            JMGF        UjFY            !         :BOESB         E:qBY           !          Fi:BN         BY:UB           !");
        sleep();
        cls();
        print_art("                                        !                                        !                                        !                   :i                   !                  8MBF   7qL            !                  B  B  iB B,           !                  B.iB  B. B            !                iYBr.EEOB 0O            !              UBPi        7BP7          !             BM             .MB         !           ,B.                uB.       !           Bi,FkZqU01  .:::    iB       !          :B      ,:,  :Yu2PZO7 N1      !           B                    rB      !           GB                   Bi      !            GB                 MP       !             jBY:            iEY        !             0YZBPZS15L;rvuNZJ          !            .B B.  ,::::BqB7            !            vB:8        B.P:            !            ULGL        B.q.            !            1YB         B,1BB           !         :BSUX2         B1iLi           !");
        sleep();
        cls();
        // this is the lemit because of memory 
        // print_art("                                        !                                        !                                        !                      .                 !              SMB   .MBP                !             iB 8P  B7 M                !              B  B  B, j                !              PB BqZM .B7:              !            jB8,       .JBBS            !           MP              1Bu          !         .B:                 Mj         !         Mu ,ii:ir.  :YujUYY. BL        !        ,B :7YSJYr.  :v,....  SB        !        ,B                    PG        !         B7                   B:        !         ,BL                .BL         !           SBr            :jM:          !            ,B8B555k5FuXZBB,            !            .BjO .,.,..JNEF             !             qS7       iF75             !            :MG.       ,ZvB             !          .ijB8        :E.BBB           !          B1iB2         B:vv,           !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                ..                      !               1BB5   GZB               !               B :B  jB Br              !               B.rB  Bi B               !               BB MMMB :B,              !            ;ZMu        iNBM            !           BB.             uBX          !          BU                 B0         !         BB F2U1rri  .LL:,:;: 80        !        .B: rrrrr;r  .Y7i,irJ :B        !         Bi                   :B        !         XB                   NG        !          ZM                 8Z         !           vBM.           .LBZ          !            :BBBPZP0PPXSSBXY.           !            urBi .:.:..BSB              !            YBq        B7B              !            MEB        kBB              !         :BXkBB        rBMSB            !          2.iBJ        .BYJ0            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                                        !             jBP   7ZB2                 !            7B B:  B.,B                 !            .B rO  B ,X                 !             BM.BGqX iBv:               !           7B0:       :v0BN             !         .PE:            .ZB7           !         Bi                 Zq          !        Bu  .:i7;.  :JvSUJJ, Br         !       :B iuS517r.  :r:,. .  uB         !       ,B                    SB         !        Bi                   B:         !        .Bi                :BJ          !          BB:            ,5Pi           !           .B5MX1L7YNuBGBE,             !            B7B ..,.: M1X:              !           :BL8        BSM              !            Bj1        B7BrY            !          ijBP1        82XYB.           !         :BrYB:        :B.              !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                .Y.                     !               :BqB.  ,0E:              !               B7 S.  B,JB              !               7B Bi qB M;              !             .UOO YM2Gi B.              !           .F0F.        5GN:            !          jB:             ,MB           !         XB                 2B.         !        iB rkqOkJGr  :YY;;:. LB         !        SM      .:.  :JN1UPOU B7        !        7B                    BX        !         B7                  .B.        !          BM                :B:         !           ZBUi           i0B.          !           kYZB0k0JLUY12EN1i            !           B:12   .,::BSB               !           7r1F       Y5NL.             !            S07       .BLBBN            !           ;BEr        BBL:             !         ,BYqB,        7N               !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !             ,      .                   !            E8Bi  .BBB                  !            B iB  B0 Br                 !            B .B. Br B                  !            EB SU8S  B;.                !         .EBj        .7XMU              !        LB:              8B:            !       UB                 .B,           !      ,B ,i;:UUY.  LL77ri7  B           !      MS :r;:r::.  .:., ..  B,          !      NB                    B:          !      .B.                  :B           !       :BL                rB            !         BE7           .7G5             !          .BBB2ZM1jU7BBBB               !           B:B  . .  ;B B               !           G:B        B:N.              !           MJB        U27BBS            !         .LMrB         B0kMr            !         SBrYB,        2B               !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                 ,                      !         uBB   :BBO                     !        ,B PX  B5 B,                    !         B: B  Bv B                     !         ;B MBNB. BBUi                  !        SMU        .vqB1                !      :ML              uBL              !     .B:                .BO             !     B7  . :77.  5ZBMNPN. Bi            !    JB 2MMqUFu.  ::       BM            !    7B                    BU            !     B:                  7B             !     rBi                SB,             !      .BB:           .0BM               !        ,LBBSN5XG0ZGOB1B                !          :NBB..:,.  MjLU               !           5rB       .B.B               !          rB,B        BFPq              !        .B80EB        .B:MBB            !         i: .B.        OM7S.            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !           :      .                     !          BBB.  :BBq                    !         UB Ek  B7 B.                   !          M YB .B iE                    !         .BB BFEq FBr.                  !       :BBr        .uNBv                !      EE.             .BB               !     MN                 rB.             !    :B i;r72j7,  17YY7iL LB             !    B: i7r;;:,.  ::,:.,.  B:            !    BL                    B:            !    rB                   FB             !     LBi                5M              !      :BBr           .5ZY               !         vBBXBPSUFSjBBBj                !          NGvB  .    GZB:               !           B7B       .B0B               !           O8B        BuBkBF            !          ,GOB        .B:5BY            !         7BjjB.        MB               !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !            rMk                         !           .B B;  jBBF                  !           Lq 8. .B rB                  !           vB BkvBB B.                  !        :GBu; .;YL ,Bi                  !       XB;          .UG1                !     ,BL               vB:              !    .B: ::i...          rB.             !    PB ivJS58Zr  YSNPL7: ;B             !    BY           .,:rLU1  Br            !    XB                    B:            !     BN                  SB             !      OB:               J8              !       ,qBU..        ,0kr               !         1BMEJZMkUkYBBB,                !         rB,O       7BvM                !          B.B        BSBv7.             !          PXXi       .BrYBB             !           MJO        PBii              !         iE1YB         Bi               !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !         kr    :j:                      !        B:Bq  ;B7B.                     !        B :B  B5 B,                     !        XU.B17B: B                      !       uBB ,ir:  BX1,                   !     LBG           7OB7                 !    BF               :Bq                !   BU                  8X               !  7B LXPjBON,  2EFUULZ, B.              !  BF                    G:              !  7B                    Bi              !   BU                  5G               !    MB.              .5X                !     78NU,  .   .,vLXB5                 !        rBBBFJUYJLL78.B                 !         N28.       BjrZ                !         rMUS        BrB                !          PLB        ;BvMXB.            !         :BYEk        BGrBq             !        ,BL:OB         BU               !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !         .                              !        BBB,  .MML                      !       UB BL  Bu.B                      !       .B B1 iB .u                      !       rB 5B5G2 Bv                      !     FBB.       rBOB,                   !   rB:             jBj                  !  UB                 GB                 ! .B:jLLi::7   r77r;.. UB                ! ZM .:iii7U.  Jk1FuJEi B:               ! EB                    B:               ! :B                   ,B                !  uB,                ,B7                !   :BBi            ,NB.                 !     iqEBPrukFXSMOEBBY                  !        BB:i,:::.. i7G1                 !        rBU2       .B Br                !         BPB        JBrB                !         iBB7        B0PB..             !        uBr8B         BU2BB:            !        qO:.MS        .Bj7.             !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !         UG:   YGB                      !        GBiB   B.PB                     !        ;B Br  B FB                     !         B iB5BB B2                     !      ,SMB       .0BL                   !    .BM:            UBi                 !   iB7                Bv                !  rB    ....   ,:::i::,B7               !  B7 08NSMGO:  i:;7JvU rB               !  BL                   :B               !  B0                   BN               !  .Br                 GB                !   .B8.             YBq                 !     vMN5J:i77viiEB0OB                  !        BPBMYU2Y,: :SiS                 !        F.Zv        BrFr                !        .B.B        iBiB                !         O.B.        BjBv ,             !       .SBr0U        ,BUFBBi            !        Bv;SB         BB ..             !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !           :.     i                     !          BBBr  7BuB                    !         .B  B  kP B.                   !          Bi B,.B:7B                    !         rB8 vU51 kBv                   !      iBMr.        .UBk                 !     MB:              FB                !    BN                 iB               !   B8 rLvFYFU, .j15qkjk.MB              !   B. .:.. ..   ..,:,.  :B              !   BL                   YB              !   ,B                   Bv              !    rBi               iBr               !     :BSr          ,rBB                 !       .0BMB0MMBMB2PBL8                 !         BiB        NSSU                !         N.B.        B5M                !         LuN7        FB1OBE             !         .EE5         Bui8N             !        vXOLB         qM                !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                                        !            BM8   7B8r                  !           ,B Mv  B7 B                  !            B BX  B v0                  !          ,rB iBMBS B:                  !        kOGL.       rMMi                !      :BS             .Zk               !     MM                 MF              !    jB :Lirr:L,  :7ri:i. BJ             !    B7 .,..:iv:  :7Y1UUY :B             !    B;                   :B             !    YB                   BE             !     PB,                NB              !      7B0.            S8u               !        :BBkL5SXNu7kBqBj                !         75LM ..ri, YB.8                !         7S:0        BiB                !          B;B        UBqi               !        :iB:B         BPSXB:            !        OBu:B         YBrYE             !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                 ,                      !         ,8r   :BMS                     !         B1YB  50 Bi                    !         Mk B  LB B:                    !         ,B jBPZj.Bk.                   !        1BM        :UBX                 !      rBY             ZB                !     NB                .B;              !    FB     ..   rZLN2U1:.B.             !    B .kOXZEU7  ,ri:.    Bi             !   .B                    B;             !    B                   LB              !    7B                 YB               !     iG7            .rBG                !       kXBr:i;;rF1SMBBLX                !         :BMB:iivi,  B M:               !          5:B        Xki2               !          BiB        :BYU               !        JNB,B         B5P               !        .FLrB         iqX5B,            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                                        !             ,B8r   LMS                 !             ZZ B  .B B2                !             1q B  qB B:                !            ,BB BZPB.5B                 !         ,kE27       .EBY               !       .BB:             FB              !      .B7                :B             !      B2 virj777   ::,,,. iB            !     rB  ,:,irLr   7jFkFS7 BL           !     7B                    BL           !      M:                  .B.           !       B7                .BU            !       .Bk:            .kM:             !         .0BF072u2UujNOBv               !          .BrB.:i:::,0EM                !          :Y70       .ZB                !          ;815        MB,               !        7BB77Y        FBU..             !        .Fu;Mv        :B5jB             !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                                        !            UBP   LB82                  !           :B OL  BS B                  !            B .M  B7 B                  !            BY B80B.8B                  !         ;NBU.       UBS:               !       ;BM             ,ME              !      7B;                SB             !     rB  ..::77,  ivr7LLr B5            !     BZ rj::i7L.  i7rrYLL  B.           !     B5                   .B            !     jB                   BB            !      2O                 GG             !       0B7.            jBj              !        .JEqjYPvP5USMBBB2               !           LBBM,iir:  8Lj               !           Y7B        BXB               !           MFB        BBB               !         X5BJB        2BEkZ,            !         kXjBr        .Br,X             !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                                        !              ,BBi   LZk                !              BY B  .B Br               !              Bv B. u8 B,               !             ,BB JZZB:2B                !          iEBYv       iB0:              !         NBi            :OZ             !       ,B:                7B            !      .Bi rvrF;7i  .::,    MG           !      LB  ,::rrrr  :YjPEE07 B.          !      FM                    B:          !      .B.                  ,B           !       LB:                ,Bi           !        i8u:            .MB.            !          :EBMU1Ujr7jYSZBX              !            BFB:i:iii B2L.              !           .BPv       UE5:              !         ,:BSB        iNB               !         BBP7B        :BB7:             !            BG         BJYB:            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                   :                    !            S1:   2MB                   !           UEiB. .O :X                  !           .U BF .B.2P                  !            B :MXXF MZr                 !          jMO.        2NU               !        LBi             7M:             !       qM                 B7            !      NE  .,.ir:  iFrj1FJ: B.           !      8 iBEUS1Xi  ,;:.,,   BJ           !     rM                    Bi           !      B:                  :B            !      ,B;                NB.            !       .BZi           .7BM              !         iuZUL777L:UONBB27              !            BSBrrr:.. .S78              !           :urP       ,NYF              !         1BBv5Y       .O8i              !          :70B         BBi              !            LM         BFiM:            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                       .                !               iBB7  .MBB               !               B.:B  JB B7              !               Br B: BB B               !              .BB GBOB.FB               !           .BBGi        YB8:            !          ZBY             :BP           !         BB                 M8          !        ZB :;:iLr;.  r7Yrrr: Br         !        B  i7:r77i.  i7L7r7: LB         !        B.                   UB         !        XG                   B1         !         Nq                .BP          !          UBu.           .BBi           !            LBBBYj7jO5FBBBv             !            UiMB ,..:. BEB              !            BiB.       BrB              !         ,BZBUB        BEB              !         :B05B:        BPBr.            !            BB         BE:BM            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                   .                    !                  FBBi   rBL            !                  M.iB  iB B,           !                  G rB  B. B            !               .v0B:.BSBB.BY            !             ;MBBY        kMX           !           .BB.             XB          !          .Bv                rB         !          Br SXqNqkO   ::.    iM        !         YB     .,ir  .XEkEBB2 BL       !         rB                    B7       !          MU                   B.       !           BF                .BX        !            GBk            .BBi         !             ZEBBGXF52UY7GB27           !            .Z.B  :i:i,qBB5             !            N,BU       j1M.             !           .B:B        BLB,             !         0BqjBF        BM8GB.           !         .Z71B         B; :U            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                         .              !                 ;BMi   BqM             !                 B; B  i8 BY            !                 O2 B  BU B.            !                ,BB BOEB kB             !             .8BEi        7BB:          !            1Bv             :BU         !           BB                 BF        !          EB ::,irr;   r7Liri: B7       !          Bi r;.rr7i.  i77r;ri rB       !          Bi                   JB       !          X5                   Bi       !           Zu                .BE        !            jGL            :ZB7         !             iBBO2u7LL55SBB1i           !             5EB  ..,..SM5B             !            :GMY       u51              !         ,BUBkB        MUk              !         :BO:B1        BUO.             !            GB         BX:BJ            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                      .Z;               !               .BBX   BjXr              !               YB B7  B .B              !                B :B:iBiYM              !                Bk Fuj7 ;FG0,           !             ,XEU          YBM          !            BB,              vB:        !           8B             . . :B.       !          .B  .rYkSY  .MMEZ2vr jB       !          Br jF2Jvi,.          :B       !          Bq                   SB       !          YB                  iB        !           2Z                0B.        !            :jq,          78BL          !              BBBSSNkZBMBBBG            !             j0XG       UY1r            !           ::BUB        BrB.            !          BBqYBi        B7B             !           rvBB        UEO              !             B         B2PO.            !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                    r,    ,v            !                   B5Bj  vB7B           !                   B :M  5S B           !                   Bi,Bi7BiiB           !                 v5Bi iL27 MB7          !               8Bq:         .5BL        !             :B2               0B       !            rB,                 kM      !            B: X5i200k. ,EZPuUjY.Br     !            B               ...  XB     !            B                    BU     !            LZ                  rB      !             JF.               MB       !              iBX;:..      .7kB1        !              M7UMLJqPS18BNBP,          !             ;B,B        MPE            !             B:Bi       rXG2            !          EPNG8G        B7k             !          qB7UB        ,BLM.            !            iB,        BB7LB;           !");
        // sleep();
        // cls();
        // print_art("                                        !                                        !                                        !                   :MB:   2BB           !                   BZrB  .B Br          !                   NL B7 UB Br          !                   iB jBUMZ Bi          !                 70B8       .EB5        !               iBj.            UO,      !              1B                 BL     !             NB   ,:iii   7:::iii,B;    !            .B .Gk0qSNP. .U7i7Y7; 0B    !            .B                    MB    !             BP                   Bi    !             ,B,                 BP     !              .BP.            .BBi      !               ,BB51NuUYjL7vBBB7        !              :B;U ,i:rL;rvNB           !              B.B5       rqBr           !             NUUB        B0B            !            :B:B        :BBi            !          BB0rBu        BZJZ;           !          .rrMM         B:iOB           !");
        // sleep();
        // cls();
    }


    // show how many color are available 
    // int *base_video = (int *) 0xb8001;
    // int i = (int) 0x00;
    // int a = 0 ;
    // while(a< 16){
    //     *base_video = i;
    //     i +=(int) 0x10;
    //     base_video += 2;
    //     a++; 
    // }
    



    // screen saver test - works 
    // while(1){
    //     print_art("  _________! < Cool_OS >!  ---------!       \\                    / \\  //\\!        \\    |\\___/|      /   \\//  \\!             /0  0  \\__  /    //  | \\ \\    !            /     /  \\/_/    //   |  \\  \\  !            @_^_@'/   \\/_   //    |   \\   \\ !            //_^_/     \\/_ //     |    \\    \\!         ( //) |        \\///      |     \\     \\!       ( / /) _|_ /   )  //       |      \\     _\\!     ( // /) '/,_ _ _/  ( ; -.    |    _ _\\.-~        .-~~~^-.!   (( / / )) ,-{        _      `-.|.-~-.           .~         `.!  (( // / ))  '/\\      /                 ~-. _ .-~      .-~^-.  \\!  (( /// ))      `.   {            }                   /      \\  \\!   (( / ))     .----~-.\\        \\-'                 .~         \\  `. \\^-.!              ///.----..>        \\             _ -~             `.  ^-`  ^-_!                ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~!                                                                   /.-~!");
        
    //     sleep();
        
    //     cls();
        
    //     print_art("   _________!  < Cool_OS >!   ---------!     \\!      \\!          .--.!         |o_o |!         |:_/ |!        //   \\ \\!       (|     | )!      /'\\_   _/`\\!      \\___)=(___/!");
        
    //     sleep();
        
    //     cls();
    // }






    
    
    // print msg 
    // char *msg = "Hello from Kernel :) ";
    // char *base_video = (char*) 0xb8000;
    // while(*msg){
    // *base_video  = *msg ;
    // base_video +=2; 
    // msg++; 
    // }


    while(1){
        
    }
}






// void print(){
//     char *base = (char *) 0xb8000;
    
//     char *ch = 'Z';
//     *base = *ch;
//     while(1){

//     } 
// }


