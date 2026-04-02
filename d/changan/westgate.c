// /d/changan/westgate.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "安定門");
        set  ("long",  @LONG
這裏便是長安西門----安定門。長安爲多朝古都，果然不同凡響，
城牆以石灰、糯米和土夯成，固若金湯。出城往西門便可直通蘭州，幾
名官兵正在守門。
LONG);
        //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
        set("exits",  ([  //sizeof()  ==  4
            "west"  :  __DIR__"road7",
            "east"  :  __DIR__"westroad1",
        ]));

        set("objects",  ([  //sizeof()  ==  1
                "/d/city/npc/wujiang"  :  1,
                "/d/city/npc/bing"  :  1,
        ]));
        set("outdoors",  "changan");
        set("no_clean_up",  0);
	set("coor/x", -5070);
	set("coor/y", 1000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

