bool check(Data d, Data limit_min, Data limit_max) {
    if ((limit_min.mst <= d.mst) and (d.mst <= limit_max.mst) and (limit_min.tmp_pole <= d.tmp_pole) and (d.tmp_pole <= limit_max.tmp_pole) and (limit_min.tmp_eq <= d.tmp_eq) and (d.tmp_eq <= limit_max.tmp_eq) and (limit_min.ox_mpercent <= d.ox_mpercent) and (d.ox_mpercent <= limit_max.ox_mpercent)
        and (limit_min.co2_mpercent <= d.co2_mpercent) and (d.co2_mpercent <= limit_max.co2_mpercent)) {
        return true;
    }
    return false;
}
