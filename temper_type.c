#include <stdlib.h>
#include <stdbool.h>
#include <wchar.h>

#include "temper_type.h"

// This is an array of known TEMPer types.
temper_type known_temper_types[]={
	{
		.name="TEMPer2HumiV1.0",
		.ignored=true,
		.vendor_id=0x0c45,
		.product_id=0x7402,
		.interface_number=0
	},
	{
		.name="TEMPer2HumiV1.0",
		.ignored=false,
		.vendor_id=0x0c45,
		.product_id=0x7402,
		.interface_number=1,
		.temp_report_length=8,
		.temp_report={1,0x80,0x33,1,0,0,0,0},
		.high_byte_offset=2,
		.low_byte_offset=3
	},
	{
		.name="TEMPerV1.2",
		.ignored=true,
		.vendor_id=0x0c45,
		.product_id=0x7401,
		.interface_number=0
	},
	{
		.name="TEMPerV1.2",
		.ignored=false,
		.vendor_id=0x0c45,
		.product_id=0x7401,
		.interface_number=1,
		.temp_report_length=8,
		.temp_report={1,0x80,0x33,1,0,0,0,0},
		.high_byte_offset=2,
		.low_byte_offset=3
	},
	{
		.name="TEMPer, TEMPerNTC or TEMPerHUM",
		.ignored=true,
		.vendor_id=0x1130,
		.product_id=0x660c,
		.interface_number=0
	},
	{
		.name="TEMPer (experimental)",
		.ignored=false,
		.vendor_id=0x1130,
		.product_id=0x660c,
		.product_string=L"TEMPer",
		.interface_number=1,
		.temp_report_length=8,
		.temp_report={0x54,0,0,0,0,0,0,0},
		.high_byte_offset=0,
		.low_byte_offset=1
	},
	{
		.name="TEMPerHUM (experimental)",
		.ignored=false,
		.vendor_id=0x1130,
		.product_id=0x660c,
		.product_string=L"TEMPerHUM",
		.interface_number=1,
		.temp_report_length=8,
		.temp_report={0x48,0,0,0,0,0,0,0},
		.high_byte_offset=0,
		.low_byte_offset=1
	},
	{ .name=NULL } // List terminator
};

// Get the temper_type that matches the given hid_device_info
temper_type* get_temper_type( struct hid_device_info *info )
{
	temper_type *type;
	for ( type = known_temper_types; type->name != NULL; type++ )
	{
		if (
			type->vendor_id == info->vendor_id &&
			type->product_id == info->product_id &&
			type->interface_number == info->interface_number &&
			(
				type->product_string == NULL ||
				wcscmp( type->product_string, info->product_string ) == 0
			)
		)
		{
			return type;
		}
	}
	return NULL;
}
