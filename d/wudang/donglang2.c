// Room: donglang2.c 東廂走廊
inherit RESTROOM_OUT;

void create()
{
    set("short", "東廂走廊");
    set("long", @LONG
你走在一條走廊上，隱約可以聽到東邊傳來呼吸聲，似乎有人正在
那裏練功，北邊有一扇門 (men)，好象是虛掩着。南邊是間竹子扎就的
屋子，十分的素雅，裏面飄出一陣陣的茶香，有人輕聲細語地不知說那
些什麼，引得女孩子“喫喫”笑出聲來。
LONG );

    set("exits", ([
        "east" : __DIR__"liangongfang",
        "south" : __DIR__"chashi",
        "west" : __DIR__"donglang1",
    ]));
  set("no_clean_up", 0);
	set("coor/x", -2030);
	set("coor/y", -920);
	set("coor/z", 90);
	set("door_name","門");
	set("door_dir","north");
	set("restroom",__DIR__"xiuxishi");
	set("open_door_msg","門上掛了個牌子：南柯夢處。\n");
	set("inside_msg",   "門上掛了個牌子：請毋打擾\n");
	set("no_one_msg",   "門上掛了個牌子：休息室。\n");
	set("item_desc/door",(: look_men : ));
	set("item_desc/men", (: look_men : ));
	setup();
}
