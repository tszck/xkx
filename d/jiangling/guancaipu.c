//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "棺材鋪");
	set ("long", @LONG
這是一家賣棺材的店鋪，門面不大，卻有個後院用來擺放做好的棺
材。掌櫃的站在門口，似笑非笑地盯着來往的客人。兵荒馬亂的年頭，
這死人的生意還挺興隆。一縷光線透過櫃檯後的小門，照在一副剛漆好
的棺材板上，亮閃閃地有些晃眼。
LONG);
	set("exits", ([ 
		"east" : __DIR__"xijie2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -2020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
