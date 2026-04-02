//tan2.c

inherit ROOM;

void create()
{
	set("short", "嘉興南湖 ");
	set("long",
		"這裏是嘉興南湖水下 ，四周倒還漸漸有些昏暗了，幾道天光從頭頂的潭水中投射下\n"
		"來，此時也不那麼瑰麗了，昏沉沉的猶如天邊的晚霞。腳下漆黑一片也不知有\n"
		"些什麼。四周的水流也沒有那麼平靜了，似乎在向一個方向流動着。你不由心中\n"
		"一動：不會有暗流吧！！\n"

	);
	set("exits", ([
		"up"   : __DIR__"tan1",
		"down" : __DIR__"tan3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
