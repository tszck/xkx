// /d/changan/lamamiao.c

inherit  ROOM;

void  create  ()
{
	set  ("short",  "喇嘛廟");
	set  ("long",  @LONG
這裏原是西北和康藏一帶喇嘛進京時的住宿地，後來建成格魯派（
黃教）寺廟。由於這裏進出都是喇嘛，因此大家都叫這裏喇嘛廟。真名
廣仁寺反而沒多少人知道。寺門高掛康熙御書“慈雲西蔭”匾額一塊。
LONG);
	set("exits",  ([  //sizeof()  ==  4
		"east"  :  __DIR__"northroad1",
	]));
	set("outdoors",  "changan");
	set("coor/x", -5050);
	set("coor/y", 1020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
