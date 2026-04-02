// /d/changan/clubup.c
 
//changan  city

inherit  ROOM;

void  create  ()
{
        set  ("short",  "長安二樓");
        set  ("long",  @LONG 
樂坊樓上顯得格外熱鬧，走廊裏人來人往，幾間屋子裏人聲嘈雜，
牌籤骨骰錢幣落盤的聲音不絕。看樣子，客人們賭得正歡呢。
LONG); 
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));

        set("exits",  ([  //sizeof()  ==  4
                "up"  :  __DIR__"clubpoem",
		"west"  :  __DIR__"duchang1",
                "east"  :  __DIR__"duchang2",
                "north"  :  __DIR__"duchang3",
                "south"  :  __DIR__"duchang4",
                "down"  :  __DIR__"club",
        ]));

        set("objects",  ([  //sizeof()  ==  1
//               __DIR__"npc/libai"  :  1,
                 __DIR__"obj/tables"  :  3,
        ]));


//      set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
