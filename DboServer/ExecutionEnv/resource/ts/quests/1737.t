CNtlTSTrigger
{
	sm = 1;
	sq = 1;
	qc = 6;
	rq = 0;
	tid = 1737;
	title = 173702;

	CNtlTSGroup
	{
		gid = 0;

		CDboTSContGAct
		{
			cid = 101;
			elnk = 255;
			nextlnk = 254;
			prelnk = "100;";

			CDboTSActSToCEvt
			{
				apptype = 0;
				eitype = 6;
				esctype = 0;
				ectype = -1;
				etype = 1;
				taid = 1;
			}
		}
		CDboTSContGAct
		{
			cid = 252;
			elnk = 255;
			nextlnk = 253;
			prelnk = "2;";
		}
		CDboTSContEnd
		{
			cid = 254;
			prelnk = "101;";
			type = 1;
		}
		CDboTSContEnd
		{
			cid = 253;
			prelnk = "252;1;0;";
			type = 0;
		}
		CDboTSContStart
		{
			cid = 0;
			stdiag = 173707;
			nolnk = 253;
			rm = 0;
			yeslnk = 1;

			CDboTSCheckLvl
			{
				maxlvl = 100;
				minlvl = 49;
			}
			CDboTSClickNPC
			{
				npcidx = "5063105;";
			}
			CDboTSCheckClrQst
			{
				and = "1736;";
				flink = 1;
				flinknextqid = "1740;";
				not = 0;
			}
		}
		CDboTSContGAct
		{
			cid = 2;
			elnk = 252;
			nextlnk = 3;
			prelnk = "1;";

			CDboTSActNPCConv
			{
				conv = 173709;
				ctype = 1;
				idx = 5063105;
				taid = 2;
			}
			CDboTSActSToCEvt
			{
				dt2 = 173725;
				otype2 = 1;
				widx1 = 1;
				iidx0 = -1;
				otype1 = 1;
				widx2 = 1;
				dt0 = 173721;
				esctype = 0;
				iidx1 = -1;
				it1 = 173722;
				otype0 = 1;
				tidx2 = 3142207;
				dt1 = 173723;
				etype = 0;
				iidx2 = -1;
				it0 = 173720;
				taid = 3;
				tidx1 = 3242106;
				widx0 = 1;
				apptype = 0;
				eitype = 6;
				tidx0 = 1653112;
				ectype = -1;
				it2 = 173724;
			}
			CDboTSActRegQInfo
			{
				cont = 173708;
				gtype = 2;
				area = 173701;
				goal = 173704;
				grade = 132203;
				rwd = 100;
				scitem = -1;
				sort = 173705;
				stype = 2;
				taid = 1;
				title = 173702;
			}
		}
		CDboTSContGCond
		{
			cid = 3;
			prelnk = "2;";
			nolnk = 255;
			rm = 0;
			yeslnk = 100;

			CDboTSCheckSToCEvt
			{
				itype = 6;
			}
		}
		CDboTSContReward
		{
			canclnk = 255;
			cid = 100;
			rwdzeny = 0;
			desc = 173714;
			nextlnk = 101;
			rwdexp = 0;
			rwdtbl = 173701;
			rwdtype = 0;
			ltime = -1;
			prelnk = "3;";
			usetbl = 1;

			CDboTSClickNPC
			{
				npcidx = "5063105;";
			}
		}
		CDboTSContProposal
		{
			cancellnk = 253;
			cid = 1;
			cont = 173708;
			gtype = 2;
			oklnk = 2;
			area = 173701;
			goal = 173704;
			sort = 173705;
			prelnk = "0;";
			ds = 1;
			grade = 132203;
			rwd = 100;
			title = 173702;
		}
	}
}

