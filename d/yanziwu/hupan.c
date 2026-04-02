// Room: /d/yanziwu/hupan.c
// Date: Feb.14.1998 by Java

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "太湖湖畔");
	set("long", @LONG
太湖(hu)處江浙之間。她襟帶三江，東南之水盡匯於此，周行五百
裏，古稱五湖。矗立湖岸，唯見長天遠波，放眼皆碧，七十二峯蒼翠挺
立在三萬六千頃波濤之中，使人心襟大開，直欲仰天長嘯，方能表此喜
樂。
LONG );
	set("exits", ([
		"northeast" : "/d/suzhou/road5",
	]));
	set("item_desc", ([
		"hu":HIC"\n近湖畔處有一葉小舟，舟上一個綠衫姑娘正在戲水。喊("HIY"yell"HIC")一聲試試吧。\n倘若你自負輕功絕佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而過。\n" NOR,
	]));
	set("objects", ([
		"/clone/misc/dache" : 1,
	]));
	set("outdoors", "yanziwu");
	set("coor/x", 840);
	set("coor/y", -1140);
	set("coor/z", 0);
  set("yell_about", "姑娘");             // yell 船家
  set("river_type", "湖");               // 江面上傳來回響
  set("need_dodge",300);                 // 需要多少輕功
  set("come_msg_out",   "一尾小舟緩緩地駛了過來，一個採蓮少女招手讓你登舟。\n");
  set("busy_msg",       "只聽得湖面上隱隱傳來：“就來了啦……”\n");
  set("wait_msg",       "湖畔一尾小舟上一個綠衫少女細聲説到：儂有啥事體。\n");
  set("leave_msg_out",  "少女竹篙一點，小舟離岸向湖心滑去。\n");
  set("leave_msg_in",   "\n少女説了一聲“坐穩嘍”，聲音極甜極清，令人一聽之下，説不出的舒適。然後竹篙一點，扁舟向湖心滑去。\n");
  set("come_msg_in",    "少女説: “到啦，上岸吧。”，隨即一點竹篙，把舟泊好。\n");
  set("item_desc/river", HIC "\n近湖畔處有一葉小舟，舟上一個綠衫姑娘正在戲水，也許喊("
                         HIY "yell" HIC ")一聲姑娘\n(" HIY "boat" HIC
                        ")就能聽見。倘若你自負輕功絕佳,也可直接"
                        "渡水(" HIY "cross" HIC ")踏江而過。\n" NOR);
  set("boat_short", "小舟");    
  set("boat_desc",  @LONG
碧綠湖面飄蕩的一葉小舟，一個綠衫少女手執雙槳，緩緩划水，口
中唱着吳儂小曲。歌聲嬌柔無那，歡悅動心。一雙纖手皓膚如玉，映着
綠波，便如透明一般。
LONG );
  set("to",         __DIR__"muti");  // 船的終點 /*   必選   */
	setup();
}