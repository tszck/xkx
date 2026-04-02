// /d/changan/club.c

inherit  ROOM;

void  create  ()
{
        set  ("short",  "長安樂坊");
        set  ("long",  @LONG
這裏是長安城一家有名的娛樂場所。當夜幕降臨後，這裏就格外熱
鬧。進進出出的客人有達官貴人，南來北往的商旅，浪跡天涯的遊子，
三五成羣的兵士，有時也能看見一些作俗客打扮的僧人或道士。
LONG);
       //set("item_desc",  (["  ***  "  :  "  ***  ",  ]));
       set("exits",  ([  //sizeof()  ==  4
              "up"    :  __DIR__"clubup",
              "south" :  __DIR__"eastroad2",
       ]));
       set("objects",  ([  //sizeof()  ==  1
                __DIR__"obj/tables"  :  1,
                __DIR__"obj/chairs"  :  2,
       ]));
//                set("outdoors",  "changan");
	set("no_clean_up",  0);
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
