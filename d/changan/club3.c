//  Room:  /d/changan/club3
inherit  ROOM;

void  create  ()
{
    set  ("short",  "聚義廳");
    set  ("long",  @LONG
這是一間寬敞明亮的大廳，廳的正中間是一根圓形的柱子。柱子上
貼滿了各種廣告：有換房的，有賣傢俱的，但其中最多的還是找打牌搭
檔的廣告。廳的東南西北各有個門，裏面傳出“拱啊！”“斃了！”等
的叫聲。
LONG);

    set("light_up",  1);
    set("no_magic",  1);
    set("no_fight",  1);
    set("exits",  ([  /*  sizeof()  ==  2  */
        "down":  __DIR__"clubpoem",
        "west":  __DIR__"majiang",
        "east":  __DIR__"xiangqishi",
        "south": __DIR__"qishi",
        "north": __DIR__"piggy",
    ]));
    set("no_clean_up", 0);
	set("coor/x", -5030);
	set("coor/y", 1010);
	set("coor/z", 30);
	setup();
    replace_program(ROOM);
}
