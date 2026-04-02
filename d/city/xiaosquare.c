// Room: /yangzhou/xiaosquare.c
// Last Modified by Winder on Jul. 20 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小廣場");
	set("long", @LONG
這是知府衙門東牆外的一片小空場，也是揚州秋決行刑之所。因此
滿場都有肅殺之氣。在廣場中央的告示牆上，貼了幾張官府懸賞捉拿朝
廷要犯的海捕文書，下面圍觀了許多看熱鬧的人，當中不乏一些武林高
手，但是要捉拿的要犯都很扎手，很少有人隨便揭榜。但也有不少武林
後起之秀在一旁躍躍欲試。
LONG
	);
	set("exits", ([
		"north" : __DIR__"caohebeijie",
		"south" : __DIR__"caohexiaojie",
	]));
	set("outdoors", "yangzhouw");
	set("objects", ([
//		__DIR__"npc/yachai" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}

mapping *quest = ({
({
	([	"name"	:	"江湖宵小",
		"id"	:	"jianghu  xiaoxiao",
		"where"	:	__DIR__"task1/xiaoxiao",]),
	([	"name"	:	"山賊",
		"id"	:	"shan  zei",
		"where"	:	__DIR__"task1/shanzei",]),
}),
({
	([	"name"	:	"山賊",
		"id"	:	"shan  zei",
		"where"	:	__DIR__"task1/shanzei",]),
	([	"name"	:	"蓋一鳴",
		"id"	:	"gai  yiming",
		"where"	:	__DIR__"task1/gaiyiming",]),
	([	"name"	:	"常長風",
		"id"	:	"chang  changfeng",
		"where"	:	__DIR__"task1/chang",]),
	([	"name"	:	"花劍影",
		"id"	:	"hua  jianying",
		"where"	:	__DIR__"task1/hua",]),
	([	"name"	:	"逍遙子",
		"id"	:	"xiaoyao  zi",
		"where"	:	__DIR__"task1/xiao",]),
	([	"name"	:	"黃鬚道人",
		"id"	:	"huangxu  daoren",
		"where"	:	__DIR__"task1/huangxu",]),
	([	"name"	:	"惡僧",
		"id"	:	"e  seng",
		"where"	:	__DIR__"task1/eseng",]),
	([	"name"	:	"曹化淳",
		"id"	:	"cao  huachun",
		"where"	:	__DIR__"task1/cao",]),
	([	"name"	:	"朱安國",
		"id"	:	"zhu  anguo",
		"where"	:	__DIR__"task1/zhu",]),
}),
({
	([	"name"	:	"江洋大盜",
		"id"	:	"jiangyang  dadao",
		"where"	:	__DIR__"task1/dadao",]),
	([	"name"	:	"草寇",
		"id"	:	"cao  kou",
		"where"	:	__DIR__"task1/caokou",]),
	([	"name"	:	"惡霸",
		"id"	:	"e  ba",
		"where"	:	__DIR__"task1/eba",]),
//	([	"name"	:	"宋揚",
//		"id"	:	"song  yang",
//		"where"	:	__DIR__"task1/songyang",]),
	([	"name"	:	"全二風",
		"id"	:	"quan  erfeng",
		"where"	:	__DIR__"task1/quan",]),
	([	"name"	:	"孟正鵬",
		"id"	:	"meng  zhengpeng",
		"where"	:	__DIR__"task1/meng",]),
	([	"name"	:	"鮮於通",
		"id"	:	"xianyu  tong",
		"where"	:	__DIR__"task1/xian",]),
	([	"name"	:	"麥鯨",
		"id"	:	"mai  jing",
		"where"	:	__DIR__"task1/maijing",]),
	([	"name"	:	"過三拳",
		"id"	:	"guo  sanquan",
		"where"	:	__DIR__"task1/guo",]),
}),
({
	([	"name"	:	"趙一傷",
		"id"	:	"zhao  yishang",
		"where"	:	__DIR__"task1/zhao",]),
	([	"name"	:	"錢二敗",
		"id"	:	"qian  erbai",
		"where"	:	__DIR__"task1/qian",]),	
	([	"name"	:	"孫三毀",
		"id"	:	"sun  sanhui",
		"where"	:	__DIR__"task1/sun",]),
	([	"name"	:	"李四摧",
		"id"	:	"li  sicui",
		"where"	:	__DIR__"task1/li",]),
	([	"name"	:	"週五輸",
		"id"	:	"zhou  wushu",
		"where"	:	__DIR__"task1/zhou",]),
	([	"name"	:	"吳六破",
		"id"	:	"wu  liupo",
		"where"	:	__DIR__"task1/wu",]),
	([	"name"	:	"鄭七滅",
		"id"	:	"zheng  qimie",
		"where"	:	__DIR__"task1/zheng",]),
	([	"name"	:	"王八衰",
		"id"	:	"wang  bashuai",
		"where"	:	__DIR__"task1/wang",]),
	([	"name"	:	"元廣波",
		"id"	:	"yuan  guangbo",
		"where"	:	__DIR__"task1/yuan",]),
	([	"name"	:	"徐長老",
		"id"	:	"xu  zhanglao",
		"where"	:	__DIR__"task1/xu",]),
}),
({
	([	"name"	:	"阿大",
		"id"	:	"a  da",
		"where"	:	__DIR__"task1/ada",]),
	([	"name"	:	"阿二",
		"id"	:	"a  er",
		"where"	:	__DIR__"task1/aer",]),
	([	"name"	:	"阿三",
		"id"	:	"a  san",
		"where"	:	__DIR__"task1/asan",]),
	([	"name"	:	"玉真子",
		"id"	:	"yu  zhenzi",
		"where"	:	__DIR__"task1/yu",]),	
	([	"name"	:	"段延慶",
		"id"	:	"duan  yanqing",
		"where"	:	__DIR__"task1/duan",]),	
	([	"name"	:	"葉二孃",
		"id"	:	"ye  erniang",
		"where"	:	__DIR__"task1/ye",]),	
	([	"name"	:	"南海鱷神",
		"id"	:	"nanhai  eshen",
		"where"	:	__DIR__"task1/nan",]),	
	([	"name"	:	"雲中鶴",
		"id"	:	"yun  zhonghe",
		"where"	:	__DIR__"task1/yun",]),	
	([	"name"	:	"鹿杖客",
		"id"	:	"lu  zhangke",
		"where"	:	__DIR__"task1/lu",]),	
	([	"name"	:	"鶴筆翁",
		"id"	:	"he  biweng",
		"where"	:	__DIR__"task1/he",]),	
	([	"name"	:	"達爾巴",
		"id"	:	"daerba  huofo",
		"where"	:	__DIR__"task1/daerba",]),	
	([	"name"	:	"霍都",
		"id"	:	"huo  du",
		"where"	:	__DIR__"task1/huodu",]),	
}),
});
mapping *wheres=({
	([	"chinese"	:	"白駝山",
		"weizhi"	:	"/d/baituo/cao2",]),
	([	"chinese"	:	"長城",
		"weizhi"	:	"/d/changcheng/changcheng19",]),
	([	"chinese"	:	"揚州城",
		"weizhi"	:	"/d/city/jiaowai9",]),
	([	"chinese"	:	"北京城",
		"weizhi"	:	"/d/beijing/huayuan",]),
	([	"chinese"	:	"成都城",
		"weizhi"	:	"/d/chengdu/wuhouci",]),
	([	"chinese"	:	"長安城",
		"weizhi"	:	"/d/changan/gulou",]),  
	([	"chinese"	:	"大理城",
		"weizhi"	:	"/d/dali/tingyuan",]),  
	([	"chinese"	:	"峨嵋山",
		"weizhi"	:	"/d/emei/jieyindian",]),  
	([	"chinese"	:	"佛山鎮",
		"weizhi"	:	"/d/foshan/street3",]),
	([	"chinese"	:	"福州城",
		"weizhi"	:	"/d/fuzhou/gushan",]),
	([	"chinese"	:	"關外",
		"weizhi" 	:	"/d/guanwai/milin3",]),
	([	"chinese"	:	"杭州城",
		"weizhi"	:	"/d/hangzhou/shiwudong",]),
	([	"chinese"	:	"黑木崖",
		"weizhi"	:	"/d/heimuya/shijie1",]),
	([	"chinese"	:	"恆山",
		"weizhi"	:	"/d/hengshan/yuyang",]),
	([	"chinese"	:	"衡山",
		"weizhi"	:	"/d/henshan/nantaisi",]),  
	([	"chinese"	:	"黃河",
		"weizhi"	:	"/d/huanghe/weifen",]),  
	([	"chinese"	:	"華山",
		"weizhi"	:	"/d/huashan/yuntai",]),  
	([	"chinese"	:	"江陵城",
		"weizhi"	:	"/d/jiangling/longzhong",]),  
	([	"chinese"	:	"嘉興城",
		"weizhi"	:	"/d/jiaxing/njroad5",]),  
	([	"chinese"	:	"崑崙山",
		"weizhi"	:	"/d/kunlun/jiuqulang2",]),  
	([	"chinese"	:	"蘭州城",
		"weizhi"	:	"/d/lanzhou/street2",]),  
	([	"chinese"	:	"靈鷲峯",
		"weizhi"	:	"/d/lingjiu/jian",]),  
	([	"chinese"	:	"靈州城",
		"weizhi"	:	"/d/lingzhou/kongdi",]),  
	([	"chinese"	:	"洛陽城",
		"weizhi"	:	"/d/luoyang/wanghuating",]),  
	([	"chinese"	:	"光明頂",
		"weizhi"	:	"/d/mingjiao/tohtq3",]),  
	([	"chinese"	:	"祁連山",
		"weizhi"	:	"/d/qilian/zhutishan",]),  
	([	"chinese"	:	"青城山",
		"weizhi"	:	"/d/qingcheng/huyingting",]),  
	([	"chinese"	:	"嵩山",
		"weizhi"	:	"/d/songshan/junjigate",]),  
	([	"chinese"	:	"蘇州城",
		"weizhi"	:	"/d/suzhou/liuyuan",]),  
	([	"chinese"	:	"泰山",
		"weizhi"	:	"/d/taishan/tianjie",]),  	 
	([	"chinese"	:	"天龍寺",
		"weizhi"	:	"/d/tianlongsi/tading",]),  
	([	"chinese"	:	"鐵掌峯",
		"weizhi"	:	"/d/tiezhang/guangchang",]),  
	([	"chinese"	:	"華山村",
		"weizhi"	:	"/d/village/eexit",]),  
	([	"chinese"	:	"萬劫谷",
		"weizhi"	:	"/d/wanjiegu/port2",]),  
	([	"chinese"	:	"五毒教",
		"weizhi"	:	"/d/wudujiao/wdsl3",]),  
	([	"chinese"	:	"無量山",
		"weizhi"	:	"/d/wuliang/road4",]),  
	([	"chinese"	:	"無錫城",
		"weizhi"	:	"/d/wuxi/road15",]),  
	([	"chinese"	:	"襄陽城",
		"weizhi"	:	"/d/xiangyang/walls3",]),  
	([	"chinese"	:	"星宿海",
		"weizhi"	:	"/d/xingxiu/shidao",]),  
	([	"chinese"	:	"雪域",
		"weizhi"	:	"/d/xuedao/shandong2",]),  
	([	"chinese"	:	"雪山大輪寺",
		"weizhi"	:	"/d/xueshan/zoulang3",]),  
	([	"chinese"	:	"燕子塢",
		"weizhi"	:	"/d/yanziwu/qiushuan",]),
	([	"chinese"	:	"泉州",
		"weizhi"	:	"/d/quanzhou/jiangjunfu1",]),
	([	"chinese"	:	"漠北",
		"weizhi"	:	"/d/mobei/hill",]),
	([	"chinese"	:	"凌霄城",
		"weizhi"	:	"/d/lingxiao/laolang",]),
	([	"chinese"	:	"回疆",
		"weizhi"	:	"/d/huijiang/xingtang",]),		
});

void init()
{
	add_action("do_jie", ({"xian","jie"}));
}

int do_jie(string arg)
{
	object me, ob;
	mapping weizhis, target;
//	string  weishis;
	int exp, position;

	if(!arg) return 0;
	me = this_player();
	ob = this_object(); 
	exp=(int)me->query("combat_exp"); 
	weizhis = wheres[random(sizeof(wheres))];
//	weishis = quest[random(sizeof(wheres))];

	if(arg != "wenshu" && arg != "wen") return 0;

	if(me->query_condition("dali_xuncheng") ||
		me->query_condition("gb_busy") ||
		me->query_condition("xx_task") ||
		me->query_condition("gb_songxin"))
		return notify_fail("你現在正忙着做其他任務呢！\n");
	if(me->query_condition("guanfu_task"))
		return notify_fail("你已經揭過榜了，難道不想做了？！\n");
	if(me->query_temp("guanfu_task") || present("wenshu", me))
		return notify_fail("你身上還有文書，可以通過(kan wenshu)來查詢。\n");
	if(me->query_condition("guanfu_busy"))
		return notify_fail("你發現文書已經被人揭光了，看樣子要等一會了！\n");
	if(exp<50000)
		return notify_fail("你剛想伸手，忽然看到上面凶神惡煞的畫像，想了想覺得自己的這點功夫，還是算了吧。\n"); 
	if(exp>=3500000) position=5;
	else if(exp>=2000000) position=4;
	else if(exp>=1000000) position=3;
	else if(exp>=250000) position=2;
	else position=1;
//	target = quest[random(sizeof(quest))];
	target = quest[position-1][random(sizeof(quest[position-1]))]; 
//	while (sizeof(filter_array(children(target["where"]),(: clonep :))) > 0)
//	target = quest[position-1][random(sizeof(quest[position-1]))];
	
	if(exp>=380000)
	{
		tell_room(this_object(), HIY + me->name() +"推開圍觀的行人，走到近前，微微睜開眼睛，冷冷瞥了一眼告示，隨手揭了下來揣進了懷中。\n"NOR, ({ me }));
		write(HIY"你推開圍觀的行人，走到近前，微微睜開眼睛，冷冷瞥了一眼告示，隨手揭了下來揣進了懷中。\n"NOR);
	}
	if(exp<=120000)
	{
		tell_room(this_object(), HIY + me->name() +"壯了壯膽，費力拔開行人，來到近前深深吸了口氣，竭力鎮定一下緊張的心情，四下看了看，悄悄把文書揭了下來。\n"NOR, ({ me }));
		write(HIY"你壯了壯膽，費力拔開行人，來到近前深深吸了口氣，竭力鎮定一下緊張的心情，四下看了看，悄悄把文書揭了下來。\n"NOR);
	}
	if(exp>120000 && exp<380000)
	{
		tell_room(this_object(), HIY + me->name() +"分開行人來到近前，目光淡淡的掃視了幾眼告示，嘴角微微一翹，神態自如的把文書揭了下來。\n"NOR, ({me}));
		write(HIY"你分開行人來到近前，目光淡淡的掃視了幾眼告示，嘴角微微一翹，神態自如的把文書揭了下來。\n"NOR);
	}
	me->set_temp("mark/gkill1",1);
	me->set_temp("guanfu_target", target["id"]);
	me->set_temp("guanfu_targetnm", target["name"]);
	me->set_temp("path_rooms", target["where"]);
	me->set_temp("gstart_rooms", weizhis["weizhi"]);
	me->set_temp("ch_weizhi", weizhis["chinese"]);
	new(__DIR__"task1/wenshu")->move(me);
//	me->move(me->query_temp("start_rooms"));
	ob = new(me->query_temp("path_rooms"));  
//	ob->move(__DIR__"xiaosquare");
	ob->move(me->query_temp("gstart_rooms"));
  ob->random_move();
  ob->random_move();
  ob->random_move();  // 加點掛機難度 呵呵 相應把間隔縮短
        
	ob->set("owner",me->query("id"));
	me->apply_condition("guanfu_task", me->set_temp("guanfu_time", random(70)+20));
//	me->apply_condition("guanfu_busy", random(10)+5);
	me->apply_condition("guanfu_busy", random(3)+1);
	
	return 1;
}
