#include "src/encode2d.c"

#include "constants/2dDouble.h"
#include "utils/hash64.h"
#include "serialExecBase.c"

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(when_seededRandomSmoothDataGenerated_expect_ChecksumMatches),

    cmocka_unit_test_setup_teardown(given_2dDoubleInterleavedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupInterleaved, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleInterleavedArray_when_ZfpDecompressFixedPrecision_expect_ArrayChecksumMatches, setupInterleaved, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoublePermutedArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupPermuted, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoublePermutedArray_when_ZfpDecompressFixedPrecision_expect_ArrayChecksumMatches, setupPermuted, teardown),

    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedPrecision_expect_ArrayChecksumMatches, setupFixedPrec0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedPrecision_expect_ArrayChecksumMatches, setupFixedPrec1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedPrecision_expect_BitstreamChecksumMatches, setupFixedPrec2, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedPrecision_expect_ArrayChecksumMatches, setupFixedPrec2, teardown),

    cmocka_unit_test(given_2dDoubleZfpStream_when_SetRateWithWriteRandomAccess_expect_RateRoundedUpProperly),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedRate_expect_ArrayChecksumMatches, setupFixedRate0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedRate_expect_CompressedBitrateComparableToChosenRate, setupFixedRate0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedRate_expect_ArrayChecksumMatches, setupFixedRate1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedRate_expect_CompressedBitrateComparableToChosenRate, setupFixedRate1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedRate_expect_BitstreamChecksumMatches, setupFixedRate2, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedRate_expect_ArrayChecksumMatches, setupFixedRate2, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedRate_expect_CompressedBitrateComparableToChosenRate, setupFixedRate2, teardown),

    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedAccuracy_expect_ArrayChecksumMatches, setupFixedAccuracy0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_CompressedValuesWithinAccuracy, setupFixedAccuracy0, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedAccuracy_expect_ArrayChecksumMatches, setupFixedAccuracy1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_CompressedValuesWithinAccuracy, setupFixedAccuracy1, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_BitstreamChecksumMatches, setupFixedAccuracy2, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpDecompressFixedAccuracy_expect_ArrayChecksumMatches, setupFixedAccuracy2, teardown),
    cmocka_unit_test_setup_teardown(given_2dDoubleArray_when_ZfpCompressFixedAccuracy_expect_CompressedValuesWithinAccuracy, setupFixedAccuracy2, teardown),
  };

  return cmocka_run_group_tests(tests, setupRandomData, teardownRandomData);
}
