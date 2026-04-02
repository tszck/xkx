// Room: /d/taohua/caodi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
你眼前出現一大片草地，芳草如茵，灑落一地鮮豔的野花。偶爾有
兔鳥飛馳而過，盎然生機一片。草地周遭是密密層層的桃樹，陽春三月
之時，鬱鬱蔥蔥，一團綠、一團紅、一團黃、一團紫，端的是繁花似錦、
芳菲無限。草地之北是一排竹林。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaoyuan",
		"north" : __DIR__"jicui",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");
	set("objects",([
		"/d/wudang/npc/yetu" : 1,
	]));  

	set("coor/x", 9010);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "west" || dir == "east") {
		if (!me->query_temp("bagua_1") && me->query_skill("qimen-wuxing", 1) < 90)
			return notify_fail("你感覺這個桃花陣中暗藏八卦，隱隱生出阻力，將你推了回來！\n");
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++) {
			if (userp(ob[i])) {
				if (!drop_flag) {
					message_vision("$N看了看眼前這個複雜無比的八卦陣，決定丟下包袱，輕裝上陣。\n", me);
					drop_flag = 1;
				}
				message_vision("$N將$n從背上放了下來，躺在地上。\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else {
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++) {
					if (userp(deep_ob[j])) {
						if (!drop_flag) {
							message_vision("$N看了看眼前這個複雜無比的八卦陣，決定丟下包袱，輕裝上陣。\n", me);
							drop_flag = 1;
						}
				                message_vision(sprintf("$N丟下一%s$n。\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}

	return ::valid_leave(me, dir);
}