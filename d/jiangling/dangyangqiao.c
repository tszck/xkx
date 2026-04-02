//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "當陽橋");
	set ("long", @LONG
一座古木橋，已經有點搖搖欲墜。當年張飛橫矛立馬橋頭，厲聲大
喝：“吾乃燕人張翼德也，誰敢與我決一死戰？”其聲如雷，橋樑震斷，
河水倒流。橋頭樹着一塊石碑 (bei)。過橋往北，是一條長長的峽谷，
江水在谷間咆哮，宛若千軍萬馬奔騰東去。東面是城陵磯，西邊是一個
小山坡。
LONG);
	set("outdoors", "jiangling");
	set("item_desc", ([
		"bei":"\n張翼德橫矛處\n"                    
	]));

	set("exits", ([ 
		"south" : __DIR__"yidao1",
		"east"  : __DIR__"chenglingji",
		"north" : __DIR__"wuxia",
		"west"  : __DIR__"changbanpo",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
