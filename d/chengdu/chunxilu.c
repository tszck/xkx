// Room: /d/chengdu/chunxilu.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "春熙路口");
	set("long", @LONG
這裏是成都府最繁華的地帶——春熙路，並不寬的街道兩旁，店鋪
林立漢白玉砌的路面幾乎能照出人影。路上的行人摩肩接踵，都在為各
自的生計奔波着。一派繁榮，富庶的景象。
    不遠處的公告欄(sign)站着兩名衣甲鮮明的衞兵。不時警惕的看着
你。
LONG);
	set("outdoors", "chengdu");
	set("objects", ([
		__DIR__"npc/weibing" : 2,
	]));
	set("exits", ([
		"south" : __DIR__"chunxilu1",
		"north" : __DIR__"dongjie1",
	]));
	set("item_desc", ([ 
		"sign" : "成都大府，嚴禁亂來，否則弄兇！\n",
	]));
	set("coor/x", -8040);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
       
}

int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;

	if( userp(me) && dir == "south" && ob=present("wei bing",this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			if((int)(inv[i]->query("weapon_prop")) &&
				(int)(inv[i]->query("equipped")))
				return notify_fail( ob->name()+"向你喝道：你娃想造反唆，搞快放下手持兵器才能進去！\n"); 
		}
	}
	return 1;
}

