//luhn_checksum_validation.cpp

/* Take a registered ID number and starting 
 *
 * from the RIGHMOST digit add digits. Double
 *
 * every other digit DIRECTLY and to the others
 *
 * IFF doubled digit < 10. IFF doubled digit > 10.
 *
 * IFF doubled digit > 10, each of those digits
 *
 * are added separately with the rest of the
 *
 * numbers. If the sum % 10 != 0, add a check
 *
 * digit 
