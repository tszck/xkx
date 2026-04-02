//  Room:  /d/luoyang/xiaojie1.c

inherit  ROOM;

void  create  ()
{
	set("short",  "石街");
	set("long",  @LONG
洛陽是歷代皇帝之都，規模宏偉，市肆卻不甚繁華。你信步走進這
條小街，兩邊商店的門扇又黑又暗，出入其中的，大多衣裳濫褸，顯見
這裏是很大衆化的街市。北面是個小酒館。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"  :  __DIR__"xiaojie2",
		"south" :  __DIR__"eastroad",
		"north" :  __DIR__"xiaojiudian",
	]));
	set("objects",  ([
		"/d/city/npc/liumang" : 3,
	]));
	set("outdoors", "luoyang");
	set("coor/x", -400);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
