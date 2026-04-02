// xiaolu2.c
// Last Modified by winder on Aug. 1 2002

inherit RESTROOM_OUT;

void create()
{
	set("short", "小山路");
	set("long", @LONG
這裏是華山的一條小山路，地勢較為平緩，不似其它地方那麼險峻。
你走在這裏，四周靜悄悄的，你就象走進了一個世外桃源。東面好象有
一扇竹門(men)。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"southwest" : __DIR__"xiaolu1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );
	set("no_clean_up", 0);

	set("coor/x", -840);
	set("coor/y", 210);
	set("coor/z", 120);
	set("door_name","竹門");
	set("door_dir","east");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","門上掛了個牌子：華山小築\n");
	set("inside_msg",   "門上掛了個牌子：打擾一次、罰跪三天！\n");
	set("no_one_msg",   "門上掛了個牌子：華山派休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
	setup();
}
